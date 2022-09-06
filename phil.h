#ifndef PHIL_H
# define PHIL_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include "colors.h"

# define FORK_TAKEN 41
# define FORK_BREAK 42
# define ERROR -1

typedef long long	t_long;

typedef struct s_philo
{
	pthread_t ph;
	int	id;
	int left_f;
	int right_f;
}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t *forks;

}	t_mutex;


typedef struct s_arg
{
	t_philo *philo;
	t_mutex *mutex;
	t_long	total_philos;
	t_long	count_philos;
	t_long	time_to_die;
	t_long	time_to_eat;
	t_long	time_to_sleep;
	t_long	eat_limit;
	t_long	eat_count;
}	t_arg;

long long	ft_arginit(char *str, long long *res);

#endif