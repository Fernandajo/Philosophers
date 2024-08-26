/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:39 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/26 14:42:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philosophers(t_global *global);

static void	*philo_routine(void *arg) //comer dormir pensar
{
	t_philo	*philo = (t_philo *)arg;
	t_global *global = philo->global;
	
	while (1)
	{
		pthread_mutex_lock(&philo->global->data_mutex);
		if (global->dead_flag == DEAD){
			pthread_mutex_unlock(&philo->global->data_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo->global->data_mutex);
		if (is_taking_the_forks(philo))
			continue;
		is_eating(philo);
		is_sleeping(philo);
		update(global, philo->philo_id, THI);
	}
	return (0);
}

void	init_philosophers(t_global *global)
{
	int	i;

	i = 0;
	global->start_time = get_current_time();
	while (i < global->num_of_philo)
	{
		if (pthread_create(&global->philos[i].thread, NULL, philo_routine, &global->philos[i]) != 0)
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
		usleep(600);
		if(somebody_died(global) == DEAD)
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
		{	pthread_mutex_lock(&global->data_mutex);
			if (global->philos[i].meals_eaten >= global->number_of_times_must_eat)
			{
				global->dead_flag = DEAD;
				pthread_mutex_unlock(&global->data_mutex);
				return(DEAD);
			}
			pthread_mutex_unlock(&global->data_mutex);
		}
		i++;
	}
	return(ALIVE);
}

int	somebody_died(t_global *global)
{
	int		i;
	size_t	time;
	
	i = 0;
	while (i < global->num_of_philo)
	{
		time = get_current_time();
		pthread_mutex_lock(&global->data_mutex);
		if (global->dead_flag == DEAD)
		{
			pthread_mutex_unlock(&global->data_mutex);
			return (DEAD);
		}
		if (global->philos[i].eating == 0 && ((int)time - global->philos[i].last_meal > global->time_to_die))
		{
			update(global, global->philos[i].philo_id, DIE);
			global->dead_flag = DEAD;
			pthread_mutex_unlock(&global->data_mutex);
			return (DEAD);
		}
		pthread_mutex_unlock(&global->data_mutex);
		i++;
	}
	return(ALIVE);
}