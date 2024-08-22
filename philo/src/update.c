/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:56:23 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/22 20:22:34 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	update(t_global *global, int philo_id, const char *action)
{
	pthread_mutex_lock(&global->monitoring_mutex);
	if (global->dead_flag == ALIVE)
		printf("%zu %d %s\n", current_time_ms() - global->start_time, philo_id, action);
	pthread_mutex_unlock(&global->monitoring_mutex);
}

int	is_eating(t_philo *philo)
{
	//check if still have time with last meal time and 
	if (get_current_time() - )
	{
		/* code */
	}
	
	//check se lowest meal == number of meals
	// ve se 'e impar ou par
	//get current time para update do last meal time
	
}

int	take_forks(t_philo *philo)
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
		print_status(philo, "died");
		philo->global->dead_flag = DEAD;
		pthread_mutex_unlock(&philo->global->data_mutex);
		return (1);
	}
	return (0);
}
