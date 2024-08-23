/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:56:23 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/23 15:47:26 by fjoestin         ###   ########.fr       */
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
/* 	if ((int)get_current_time() - philo->last_meal > philo->global->time_to_die)
	{ */
	update(philo->global, philo->philo_id, EAT);
	pthread_mutex_lock(&philo->global->data_mutex);
	philo->last_meal = get_current_time();
	philo->eating = 1;
	pthread_mutex_unlock(&philo->global->data_mutex);
	usleep(philo->global->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->global->data_mutex);
	philo->eating = 0;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->global->data_mutex);

	// }
/* 	else
	{
		pthread_mutex_lock(&philo->global->data_mutex);
		update(philo->global, philo->philo_id, DIE);
		philo->global->dead_flag = DEAD;
		pthread_mutex_unlock(&philo->global->data_mutex);
		return (1);
	}
	return (0); */
	//get current time para update do last meal time
	
}

int	took_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (philo->meals_eaten == 0)
			usleep(200);
		pthread_mutex_lock(philo->right_fork);
		update(philo->global, philo->philo_id, RFORK);
		pthread_mutex_lock(philo->left_fork);
		update(philo->global, philo->philo_id, LFORK);
	}
	else
	{
		if (handle_one(philo))
			return (1);
		if (philo->meals_eaten == 0
			&& (philo->global->num_of_philo % 2) != 0 && philo->philo_id == 1)
			usleep(philo->global->time_to_eat * 1000);
		pthread_mutex_lock(philo->left_fork);
		update(philo->global, philo->philo_id, LFORK);
		pthread_mutex_lock(philo->right_fork);
		update(philo->global, philo->philo_id, RFORK);
	}
	return (0);
}


int	handle_one(t_philo *philo)
{
	if (philo->global->num_of_philo == 1)
	{
		pthread_mutex_lock(&philo->global->data_mutex);
		update(philo->global, philo->philo_id, DIE);
		philo->global->dead_flag = DEAD;
		pthread_mutex_unlock(&philo->global->data_mutex);
		return (1);
	}
	return (0);
}

void	is_sleeping(t_philo *philo)
{
/* 	pthread_mutex_lock(&philo->global->data_mutex);
	philo->eating = 0; */
	update(philo->global, philo->philo_id, SLE);
	// pthread_mutex_unlock(&philo->global->data_mutex);
	usleep(philo->global->time_to_sleep * 1000);
}