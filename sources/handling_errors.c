/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:20:25 by egun              #+#    #+#             */
/*   Updated: 2022/10/13 16:34:49 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handling(int argc, char **argv, t_main *main)
{
	if (init_input_struct(argc, argv, main) == FALSE)
	{
		printf("%sERROR: The number of arguments must be 4 or 5%s\n", PINK, RESET);
		return (FALSE);
	}
	else
	{
		printf("There's an error in input\n");
		if (!main->input.num_philo || !main->input.time_to_die
			|| !main->input.time_to_eat || !main->input.time_to_sleep
			|| (argc == 6 && !main->input.num_of_times_eat))
			return (FALSE);
	}
	return (TRUE);
}

int	init_input_struct(int argc, char **argv, t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->input.num_philo = philo_atoi(argv[1]);
		main->input.time_to_die = philo_atoi(argv[2]);
		main->input.time_to_eat = philo_atoi(argv[3]);
		main->input.time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->input.num_of_times_eat = philo_atoi(argv[5]);
		else
			main->input.num_of_times_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}


