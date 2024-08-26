/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:56:23 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/26 13:51:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	update(t_global *global, int philo_id, const char *action)
{
	pthread_mutex_lock(&global->monitoring_mutex);
	if (global->dead_flag == ALIVE)
		printf("%zu: Philo %d %s\n", get_current_time() - global->start_time, philo_id, action);
	pthread_mutex_unlock(&global->monitoring_mutex);
}

void	is_eating(t_philo *philo)
{
	update(philo->global, philo->philo_id, EAT);
	pthread_mutex_lock(&philo->global->data_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->global->data_mutex);
	ft_usleep(philo->global->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->global->data_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->global->data_mutex);
}

int	is_taking_the_forks(t_philo *philo)
{
	size_t	time;

	time = get_current_time();
	pthread_mutex_lock(&philo->global->dead_flag_mutex);
	if ((int)time - philo->last_meal > philo->global->time_to_die)
	{
		philo->local_dead_flag = DEAD;
		pthread_mutex_unlock(&philo->global->dead_flag_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->global->dead_flag_mutex);
		if (philo->philo_id % 2 == 0)
		{
			if (philo->meals_eaten == 0)
				usleep(200);
			pthread_mutex_lock(philo->right_fork);
			update(philo->global, philo->philo_id, FORK);
			pthread_mutex_lock(philo->left_fork);
			update(philo->global, philo->philo_id, FORK);
		}
		else
		{
			if (only_one(philo))
				return (1);
			if (philo->meals_eaten == 0
				&& (philo->global->num_of_philo % 2) != 0 && philo->philo_id == 1)
				usleep(philo->global->time_to_eat * 1000);
			pthread_mutex_lock(philo->left_fork);
			update(philo->global, philo->philo_id, FORK);
			pthread_mutex_lock(philo->right_fork);
			update(philo->global, philo->philo_id, FORK);
		}
	}
	return (0);
}


int	only_one(t_philo *philo)
{
	if (philo->global->num_of_philo == 1)
	{
		pthread_mutex_lock(&philo->global->dead_flag_mutex);
		philo->local_dead_flag = DEAD;
		pthread_mutex_unlock(&philo->global->dead_flag_mutex);
		return (1);
	}
	return (0);
}

void	is_sleeping(t_philo *philo)
{
	update(philo->global, philo->philo_id, SLE);
	ft_usleep(philo->global->time_to_sleep);
}