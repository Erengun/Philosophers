#include "phil.h"

void	ft_error(char *msg)
{
	printf(RED"%s\n"RST, msg);
	exit(0);
}

int	destroy(t_arg *arg)
{
	free(arg->philo);
	free(arg->mutex);
	free(arg);
	return (42);
}

int av_init(t_arg *arg, char** av, int ac)
{
	if (!arg && !arg->mutex && !arg->philo)
		return (ERROR);
	if (ft_arginit(av[1], &arg->total_philos) == ERROR)
		return (ERROR);
	if (ft_arginit(av[2], &arg->time_to_die) == ERROR)
		return (ERROR);
	if (ft_arginit(av[3], &arg->time_to_eat) == ERROR)
		return (ERROR);
	if (ft_arginit(av[4], &arg->time_to_sleep) == ERROR)
		return (ERROR);
	if (ac == 6 && ft_arginit(av[5], &arg->eat_limit) == ERROR)
		return (ERROR);
	printf(RED"%lld\n"RST, arg->total_philos);
	return (31);
}

int main(int ac, char **av)
{
	t_arg *arg;

	arg = malloc(sizeof(t_arg));
	arg->mutex = malloc(sizeof(t_mutex));
	arg->philo = malloc(sizeof(t_philo));
	if (ac != 6 && ac != 5)
		return (-1);
	printf("hi\n");
	if (av_init(arg, av, ac) == ERROR)
	{
		ft_error("Arg Error");
		destroy(arg);
		return (ERROR);
	}
	printf("hi There\n");
	printf(CYN"%lld\n"RST, arg->eat_limit);
	return 0;
}
