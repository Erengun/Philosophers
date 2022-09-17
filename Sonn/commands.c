/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:55:45 by egun              #+#    #+#             */
/*   Updated: 2022/09/16 19:05:39 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->forks[philo->l_fork]);
	print_message(philo, FORK);
	pthread_mutex_lock(&philo->arg->forks[philo->r_fork]);
	print_message(philo, FORK);
}

void	eat_pasta(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	philo->is_eating = 1;
	philo->last_eat = get_tick_count();
	philo->dead_limit = philo->last_eat + philo->time_to_die;
	print_message(philo, EAT);
	usleep(philo->arg->time_to_eat * 1000);
	philo->eat_number++;
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(&philo->arg->arg_mutex);
}

void	release_forks(t_philo *philo)
{
	print_message(philo, SLEEP);
	pthread_mutex_unlock(&philo->arg->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->arg->forks[philo->r_fork]);
	usleep(philo->arg->time_to_sleep * 1000);
}
