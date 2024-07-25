
#include "../inc/philo.h"

int	init_philo(int argc, char **argv, t_global *global)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if (!is_number(argv[i]) || (i < 5 && ft_atoi_philo(argv[i]) <= 0) || (i == 5 && ft_atoi_philo(argv[i]) < 0))
		{
			error_exit(ERR_NUM);
			return (1);
		}
		i++;
	}
	global->num_of_philo = ft_atoi_philo(argv[1]);
    global->time_to_die = ft_atoi_philo(argv[2]);
    global->time_to_eat = ft_atoi_philo(argv[3]);
    global->time_to_sleep = ft_atoi_philo(argv[4]);
	if (global->num_of_philo <= 0 || global->num_of_philo > 200)
	{
		error_exit(ERR_PHI);
		return (1);
	}
	if(argc == 6)
		global->number_of_times_each_philosopher_must_eat = ft_atoi_philo(argv[5]);
	else
		global->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}