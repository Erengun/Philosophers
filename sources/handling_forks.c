/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:20:59 by egun              #+#    #+#             */
/*   Updated: 2022/10/07 15:20:59 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_philo);
	if (main->forks == NULL)
		return (FALSE);
	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	unlock_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_unlock(&main->forks[i]);
		i++;
	}
}
