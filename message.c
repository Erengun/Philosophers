/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:02 by egun              #+#    #+#             */
/*   Updated: 2022/09/15 14:20:51 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	ft_error(char *msg, int flag, t_arg *arg)
{
	printf(RED"%s\n"RST, msg);
	if (flag)
		destroy(arg);
	exit(ERROR);
}

char	*type_message(int type)
{
	if (type == EAT)
		return (" is eating\n");
	else if (type == SLEEP)
		return (" is sleeping\n");
	else if (type == FORK)
		return (" has taken a fork\n");
	else if (type == THINK)
		return (" is thinking\n");
	else if (type == ATE)
		return ("must eat count reached\n");
	return (" died\n");
}

void	print_message(t_philo *philo, int type)
{
	static int	finish = 0;

	pthread_mutex_lock(&philo->print_mutex);
	if (!finish)
		printf("%d\t%s", philo->id + 1, type_message(type));
	if (type == DIE)
		finish = 1;
	pthread_mutex_unlock(&philo->print_mutex);
}
