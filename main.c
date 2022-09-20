/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:24 by egun              #+#    #+#             */
/*   Updated: 2022/09/20 15:37:23 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void 	clean_table(t_arg *arg)
{
	int	i;

	i = -1;
	if (arg->forks)
	{
		while(++i < arg->total_philos)
			pthread_mutex_destroy(&arg->forks[i]);
		free(arg->forks);
	}
	if (arg->philo)
	{
		i = -1;
		while (i < arg->total_philos)
		{
			pthread_mutex_destroy(&arg->philo[i].print_mutex);
			pthread_mutex_destroy(&arg->philo[i].eat_mutex);
		}
		free(arg->philo);
	}
	pthread_mutex_destroy(&arg->arg_mutex);
	pthread_mutex_destroy(&arg->boss);
	free(arg);
}

void	*dead_monitor(void *philo_t)
{
	t_philo	*philo;

	philo = (t_philo *)philo_t;
	while (42)
	{
		pthread_mutex_lock(&philo->print_mutex);
		if (philo->is_eating != EAT && get_tick_count() > philo->dead_limit)
		{
			print_message(philo, DIE);
			pthread_mutex_unlock(&philo->print_mutex);
			pthread_mutex_unlock(&philo->arg->boss);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->print_mutex);
		usleep(1000);
	}
}

void	*start_routine(void *philo_t)
{
	t_philo		*philo;
	pthread_t	pid;

	philo = (t_philo *)philo_t;
	philo->last_eat = get_tick_count();
	philo->dead_limit = philo->last_eat + philo->arg->time_to_die;
	if (pthread_create(&pid, NULL, &dead_monitor, philo_t) != 0)
		return (NULL);
	pthread_detach(pid);
	while (42)
	{
		take_forks(philo);
		eat_pasta(philo);
		release_forks(philo);
		print_message(philo, THINK);
	}
	return (NULL);
}

void	*eat_counter(void *arg_t)
{
	t_arg	*arg;
	int		i;
	int		total;

	arg = (t_arg *)arg_t;
	total = 0;
	while (total < arg->eat_limit)
	{
		i = -1;
		while (++i < arg->total_philos)
			pthread_mutex_lock(&arg->philo[i].eat_mutex);
		total++;
	}
	print_message(arg->philo, ATE);
	pthread_mutex_unlock(&arg->boss);
	return (NULL);
}

int	main(int ac, char **av)
{
	//TODO av_init fix, Norm, Test
	t_arg	arg;

	if (ac != 6 && ac != 5)
		return (-1);
	if (init(&arg, av, ac) == ERROR)
		ft_error("Arg Error", 1, &arg);
	if (create_thread(&arg) == ERROR)
		ft_error("Thread error", 1, &arg);
	pthread_mutex_lock(&arg.boss);
	pthread_mutex_unlock(&arg.boss);
	clean_table(&arg);
	return (0);
}
