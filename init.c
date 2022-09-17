/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:12:07 by egun              #+#    #+#             */
/*   Updated: 2022/09/17 19:24:59 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	philo_init(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->total_philos)
	{
		arg->philo[i].max_eat = arg->eat_limit;
		arg->philo[i].time_to_die = arg->time_to_die;
		arg->philo[i].is_eating = 0;
		arg->philo[i].id = i;
		arg->philo[i].l_fork = i;
		arg->philo[i].r_fork = (i + 1) % (int)arg->total_philos;
		arg->philo[i].eat_number = 0;
		pthread_mutex_init(&arg->philo[i].eat_mutex, NULL);
		pthread_mutex_lock(&arg->philo[i].eat_mutex);
		i++;
	}
}

void	mutex_init(t_arg *arg)
{
	int	i;

	i = -1;
	pthread_mutex_init(&arg->boss, NULL);
	pthread_mutex_init(&arg->arg_mutex, NULL);
	arg->forks = (pthread_mutex_t *)malloc(sizeof(arg->forks) \
			* arg->total_philos);
	if (!arg->forks)
		ft_error("There is an error occured while allocating", 1, arg);
	while (++i < arg->total_philos)
		pthread_mutex_init(&arg->forks[i], NULL);
}

int	av_init(t_arg *arg, char **av, int ac)
{
	if (!arg && !arg->philo)
		return (ERROR);
	//printf("%s, %s, %s, %s", av[1], av[2], av[3], av[4]);
	arg->total_philos = ft_arginit(av[1]);
	arg->time_to_die = ft_arginit(av[2]);
	arg->time_to_eat = ft_arginit(av[3]);
	arg->time_to_sleep = ft_arginit(av[4]);
	if (ac == 6)
		arg->eat_limit = ft_arginit(av[5]);
	else
		arg->eat_limit = -1;
	if (arg->time_to_die < 2 || arg->time_to_eat < 1 || arg->time_to_sleep < 1
		|| arg->total_philos < 1 || (ac == 6 && arg->eat_limit < 1))
		ft_error("Error: arguments", 1, arg);
	return (31);
}

void	create_thread(t_arg *arg)
{
	int			i;
	pthread_t	pid;
	void		*philo;

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
		printf("OHAAAA IS THIS KID TURKO\n");
		usleep(100);
	}
}