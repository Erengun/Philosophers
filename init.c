/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:12:07 by egun              #+#    #+#             */
/*   Updated: 2022/09/12 15:04:14 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	philo_init(t_arg *arg)
{
	int i;

	i = 0;
	while (i < arg->total_philos)
	{
		arg->philo[i].is_eating = 0;
		arg->philo[i].id = i;
		arg->philo[i].l_fork = i;
		arg->philo[i].r_fork = (i + 1) % arg->total_philos;
		arg->philo[i].eat_number = 0;
		pthread_mutex_init(&arg->philo[i].boss, NULL);
		pthread_mutex_init(&arg->philo[i].eat_mutex, NULL);
		pthread_mutex_lock(&arg->philo[i].eat_mutex);
		i++;
	}
}

int	*mutex_init(t_arg *arg)
{
	t_long	i;

	forks = arg->philo->forks;
	forks = malloc(sizeof(pthread_mutex_t) * arg->total_philos);
	if (!forks)
		ft_error("Allocation error", 1, arg);
	i = -1;
	while (++i < arg->total_philos)
		pthread_mutex_init(forks[i], NULL);
	pthread_mutex_init(&arg->philo->boss, NULL);
	return (0);
}

int av_init(t_arg *arg, char** av, int ac)
{
	if (!arg && !arg->mutex && !arg->philo)
		return (ERROR);
	if (ft_arginit(av[1], &arg->total_philos) == ERROR)
		return (ERROR);
	if (ft_arginit(av[2], &arg->time_to_die) == ERROR)
		return (ERROR);
	if (ft_arginit(av[3], &arg->time_to_eat) == ERROR)
		return (ERROR);
	if (ft_arginit(av[4], &arg->time_to_sleep) == ERROR)
		return (ERROR);
	if (ac == 6 && ft_arginit(av[5], &arg->eat_limit) == ERROR)
		return (ERROR);
	if (arg->time_to_die < 1 || arg->time_to_eat < 1 || arg->time_to_sleep < 1
		|| arg->total_philos < 1 || (ac == 6 && arg->eat_limit < 1))
		return (ft_error("Error: arguments", 1, arg));
	return (31);
}
