/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:50:26 by egun              #+#    #+#             */
/*   Updated: 2022/09/09 14:06:59 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

t_long	get_tick_count(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	destroy(t_arg *arg)
{
	free(arg->philo);
	free(arg->mutex);
	free(arg);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48) * sign;
		i++;
	}
	return (number);
}

int	ft_arginit(char *str, long long *res)
{
	if (!str)
		return (ERROR);
	*res = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (ERROR);
		*res = ft_atol(str);
		if (*res > __INT_MAX__)
			return (ERROR);
		str++;
	}
	return ((int)res);
}
