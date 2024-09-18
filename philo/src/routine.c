/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:29:52 by fjoestin          #+#    #+#             */
/*   Updated: 2024/09/18 20:06:45 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_routine(t_global *global);

static void	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_global	*global;

	philo = (t_philo *)arg;
	global = philo->global;
	while (!dead_loop(philo))
	{
		if (is_taking_the_forks(philo))
			continue ;
		is_eating(philo);
		is_sleeping(philo);
		//update(global, philo->philo_id, THI);
	}
	return (0);
}

void	init_routine(t_global *global)
{
	int	i;

	i = 0;
	global->start_time = get_current_time();
	while (i < global->num_of_philo)
	{
		if (pthread_create(&global->philos[i].thread, NULL,
				philo_routine, &global->philos[i]) != 0)
			ft_exit(global, 1, ERR_INI);
		i++;
	}
}

void	join_threads(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		if (pthread_join(global->philos[i].thread, NULL) != 0)
			ft_exit(global, 1, ERR_JOI);
		i++;
	}
}

void	monitor(t_global *global)
{
	while (42)
	{
		usleep(200);
		if (somebody_died(global) == DEAD)
			return ;
		if (all_ate(global) == DEAD)
			return ;
	}
}

int	all_ate(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		if (global->number_of_times_must_eat != -1)
		{
			pthread_mutex_lock(&global->data_mutex);
			if (global->philos[i].meals_eaten >= 
				global->number_of_times_must_eat)
			{
				pthread_mutex_lock(&global->dead_flag_mutex);
				global->dead_flag = DEAD;
				pthread_mutex_unlock(&global->dead_flag_mutex);
				pthread_mutex_unlock(&global->data_mutex);
				return (DEAD);
			}
			pthread_mutex_unlock(&global->data_mutex);
		}
		i++;
	}
	return (ALIVE);
}
