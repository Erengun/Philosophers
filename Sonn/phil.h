/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:24 by egun              #+#    #+#             */
/*   Updated: 2022/09/15 13:46:00 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include "colors.h"

# define EAT		0
# define SLEEP		1
# define FORK		2
# define THINK		3
# define DIE		4
# define ATE		5
# define ERROR 		-1

typedef long long	t_long;

struct				s_arg;

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		ph;
	int				id;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	print_mutex;
	int				is_eating;
	int				eat_number;
	int				max_eat;
	t_long			time_to_die;
	int				l_fork;
	int				r_fork;
	t_long			last_eat;
	t_long			dead_limit;
}	t_philo;

typedef struct s_arg
{
	t_philo			*philo;
	t_long			total_philos;
	t_long			count_philos;
	t_long			time_to_die;
	t_long			time_to_eat;
	t_long			time_to_sleep;
	t_long			eat_limit;
	t_long			eat_count;
	t_long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	boss;
	pthread_mutex_t	arg_mutex;
}	t_arg;

int			av_init(t_arg *arg, char **av, int ac);
int			ft_arginit(char *str, long long *res);
t_long		get_tick_count(void);
int			destroy(t_arg *arg);
void		ft_error(char *msg, int flag, t_arg *arg);
void		mutex_init(t_arg *arg);
void		create_thread(t_arg *arg);
void		print_message(t_philo *philo, int type);
void		*eat_counter(void *arg_t);
void		*start_routine(void *philo_t);
void		*dead_monitor(void *philo_t);
void		take_forks(t_philo *philo);
void		eat_pasta(t_philo *philo);
void		release_forks(t_philo *philo);

#endif
