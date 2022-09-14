/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:55:45 by egun              #+#    #+#             */
/*   Updated: 2022/09/14 18:43:04 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Take_forks, Release_forks, Eat_pasta functions
#include "phil.h"

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(&arg->forks[philo->l_fork]);
	print_message(philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, FORK);
}