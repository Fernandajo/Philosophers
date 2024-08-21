
#include "../inc/philo.h"

int	init_global(int argc, char **argv, t_global *global)
{
	if(check_numbers(argc, argv) == 0)
	{
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
			global->number_of_times_must_eat = ft_atoi_philo(argv[5]);
		else
			global->number_of_times_must_eat = -1;
		global->lowest_meal = 0;
		global->dead_flag = 0;
	}
	// printf("Number of philos: %i\n", global->num_of_philo);
	// printf("Time to die: %i\n", global->time_to_die);
	// printf("Time to eat: %i\n", global->time_to_eat);
	// printf("Time to sleep: %i\n", global->time_to_sleep);
	// printf("Number of times they need to eat: %i\n", global->number_of_times_must_eat);
	// printf("lowest_meal: %d\n", global->lowest_meal);
    // printf("dead_flag: %d\n", global->dead_flag);
	if (!init_mutex(global))
	{
		error_exit("erro no mutex\n");
		return (1);
	}
	if (!init_philo(global))
	{
		error_exit("erro no philo\n");
		return (1);	
	}
	return (0);
}

int	check_numbers(int argc, char **argv)
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
	return (0);
}

int	init_mutex(t_global *global)
{
	int	i;

	i = 0;
	global->start_time = get_current_time();
	if (pthread_mutex_init(&global->philo_meal_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&global->monitoring_mutex, NULL) != 0)
		return(1); // can I add error and exit?
	global->fork_locks = malloc(global->num_of_philo * sizeof(pthread_mutex_t));
	if (!global->fork_locks)
		return (1);
	while(i < global->num_of_philo)
	{
		if (pthread_mutex_init(&global->fork_locks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_philo(t_global *global)
{
	int	i;

	i = 0;
	global->philos = (t_philo *)malloc(global->num_of_philo * sizeof(t_philo));
	if(!global->philos)
		return (1);
	while (i < global->num_of_philo)
	{
		printf("aqui %i\n", i);
		global->philos[i].philo_id = i + 1;
		printf("philo id: %i\n", global->philos[i].philo_id);
		global->philos[i].eating = 0;
		global->philos[i].meals_eaten = 0;
		global->philos[i].last_meal = global->start_time;
		global->philos[i].local_dead_flag = 0;
		global->philos[i].local_lowest_meal = 0;
		global->philos[i].global = &global; //check this
		global->philos[i].right_fork = &global->fork_locks[i];
		global->philos[i].left_fork = &global->fork_locks[(i + 1) % global->num_of_philo];
		i++;
	}
	return (0);
}