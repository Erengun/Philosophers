/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:21:10 by egun              #+#    #+#             */
/*   Updated: 2022/10/07 15:21:10 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_main *main)
{
	int	i;
	int	j;

	main->philo = malloc(sizeof(t_philo) * main->input.num_philo);
	if (main->philo == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (j < main->input.num_philo)
	{
		fill_philo_struct(main, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(main, i, j);
	return (TRUE);
}

void	fill_philo_struct(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].num_of_times_ate = 0;
	main->philo[i].time_to_die = 0;
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = j;
}
