/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:28:10 by fjoestin          #+#    #+#             */
/*   Updated: 2024/09/16 15:32:47 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_global	*init_global(int argc, char **argv, t_global *global)
{
	if (check_numbers(argc, argv) == 0)
	{
		global = (t_global *)malloc(sizeof(t_global));
		global->num_of_philo = ft_atoi_philo(argv[1]);
		global->time_to_die = ft_atoi_philo(argv[2]);
		global->time_to_eat = ft_atoi_philo(argv[3]);
		global->time_to_sleep = ft_atoi_philo(argv[4]);
		if (global->num_of_philo <= 0 || global->num_of_philo > 200)
			ft_exit(global, 1, ERR_PHI);
		if (argc == 6)
			global->number_of_times_must_eat = ft_atoi_philo(argv[5]);
		else
			global->number_of_times_must_eat = -1;
		global->dead_flag = ALIVE;
		global->start_time = 0;
	}
	if (init_mutex(global))
		ft_exit(global, 1, ERR_MUT);
	if (init_philo(global))
		ft_exit(global, 1, ERR_INI);
	return (global);
}

int	check_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]) || (i < 5 && ft_atoi_philo(argv[i]) <= 0)
			|| (i == 5 && ft_atoi_philo(argv[i]) < 0))
		{
			ft_exit(NULL, 1, ERR_NUM);
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
	global->start_time = 0;
	pthread_mutex_init(&global->data_mutex, NULL);
	pthread_mutex_init(&global->monitoring_mutex, NULL);
	pthread_mutex_init(&global->dead_flag_mutex, NULL);
	global->fork_locks = (pthread_mutex_t *)malloc(global->num_of_philo * sizeof(pthread_mutex_t));
	if (!global->fork_locks)
		return (1);
	while (i < global->num_of_philo)
	{
		if (pthread_mutex_init(&global->fork_locks[i], NULL))
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
	if (!global->philos)
		return (1);
	while (i < global->num_of_philo)
	{
		global->philos[i].philo_id = i + 1;
		global->philos[i].meals_eaten = 0;
		global->philos[i].last_meal = 0;
		global->philos[i].local_dead_flag = 0;
		global->philos[i].global = global; //check this
		global->philos[i].right_fork = &global->fork_locks[i];
		if (global->num_of_philo > 1)
		{
			global->philos[i].left_fork = &global->fork_locks[(i + 1) % global->num_of_philo];
		}
		else
			global->philos[i].left_fork = NULL;
		i++;
	}
	return (0);
}

int	somebody_died(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_mutex_lock(&global->dead_flag_mutex);
		if (global->philos[i].local_dead_flag == DEAD)
		{
			update(global, global->philos[i].philo_id, DIE);
			global->dead_flag = DEAD;
			pthread_mutex_unlock(&global->dead_flag_mutex);
			return (DEAD);
		}
		pthread_mutex_unlock(&global->dead_flag_mutex);
		i++;
	}
	return (ALIVE);
}
