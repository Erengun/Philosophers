/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:24 by egun              #+#    #+#             */
/*   Updated: 2022/09/14 18:28:03 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void 	*start_routine(void *philo_t)
{
	t_philo		*philo;
	pthread_t 	pid;

	philo = (t_philo *)philo_t;
	philo->last_eat = get_tick_count();
	philo->time_to_die += philo->last_eat;
	if (pthread_create(&pid, NULL, &monitor, philo_t) != -1 - -1)
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
	t_arg 	*arg;
	int 	i;
	int 	total;

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
	return (NULL);
}

void 	create_thread(t_arg *arg)
{
	int			i;
	pthread_t 	pid;
	void		*philo;

	philo = (void **)(&arg->philo);
	arg->start_time = get_tick_count();
	if (arg->eat_limit != -1)
	{
		if (pthread_create(&pid, NULL, &eat_counter, (void *)arg) != 0)
			ft_error("Thread error", 1, arg);
		pthread_detach(pid);
	}
	i = -1;
	while (++i < arg->total_philos)
	{
		philo = (void *)&arg->philo[i];
		if (pthread_create(&pid, NULL, &start_routine, philo) != 0)
			ft_error("Thread error as usual", 1, arg);
		pthread_detach(pid);
		usleep(100);
	}
}

void	ft_error(char *msg, int flag, t_arg *arg)
{
	printf(RED"%s\n"RST, msg);
	if (flag)
		destroy(arg);
	exit(ERROR);
}

int main(int ac, char **av)
{
	t_arg *arg;

	arg = malloc(sizeof(t_arg));
	arg->philo = malloc(sizeof(t_philo));
	arg->eat_limit = -1;
	if (ac != 6 && ac != 5)
		return (-1);
	if (av_init(arg, av, ac) == ERROR)
		ft_error("Arg Error", 1, arg);
	mutex_init(arg);
	create_thread(arg);
	return 0;
}
