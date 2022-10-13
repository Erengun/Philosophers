/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:21:22 by egun              #+#    #+#             */
/*   Updated: 2022/10/07 15:21:22 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (error_handling(argc, argv, &main) == FALSE)
		return (1);
	if (create_philos(&main) == FALSE)
		return (1);
	if (create_forks(&main) == FALSE)
		return (1);
	if (main.input.num_philo == 1)
	{
		if (just_one_philo(&main) == FALSE)
			return (1);
		return (0);
	}
	if (create_threads(&main) == FALSE)
		return (1);
	if (destroy_threads(&main) == FALSE)
		return (1);
	philo_free(&main);
	return (0);
}

int	just_one_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	main->t0 = get_time();
	philo_print(main, 1, B_BLUE, FORK);
	exec_action(main->input.time_to_die);
	philo_print(main, 1, PINK, DIED);
	philo_free(main);
	return (TRUE);
}
