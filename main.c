#include "phil.h"

void 	start_routine(t_arg *arg)
{
	int i;
	arg->start_time = get_tick_count();
	if (arg->philo->eat_number != -1)
	{
		if (&(arg->philo->ph), NULL,)
	}
}

void	ft_error(char *msg, int flag, t_arg *arg)
{
	printf(RED"%s\n"RST, msg);
	if (flag)
		destroy(arg);
	exit(ERROR);
}

int main(int ac, char **av)
{
	t_arg *arg;

	arg = malloc(sizeof(t_arg));
	arg->philo = malloc(sizeof(t_philo));
	arg->eat_limit = -1;
	if (ac != 6 && ac != 5)
		return (-1);
	if (av_init(arg, av, ac) == ERROR)
		ft_error("Arg Error", 1, arg);
	arg->start_time = get_tick_count();
	if (start_routine(arg) == ERROR)
		ft_error("Aga b", 1, arg);
	return 0;
}
