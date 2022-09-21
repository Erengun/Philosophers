/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:02 by egun              #+#    #+#             */
/*   Updated: 2022/09/21 20:15:25 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	ft_error(char *msg, int flag, t_arg *arg)
{
	printf("%s\n", msg);
	(void)msg;
	if (flag)
		clean_table(arg);
	return (ERROR);
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

	pthread_mutex_lock(&philo->arg->print_mutex);
	if (!finish)
		printf("%lld\t%d %s", (get_tick_count() - philo->arg->start_time) , philo->id + 1, type_message(type));
	if (type == DIE || type == ATE)
		finish = 1;
	pthread_mutex_unlock(&philo->arg->print_mutex);
}
