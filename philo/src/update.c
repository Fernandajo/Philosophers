/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:56:23 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/30 14:53:26 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	update(t_global *global, int philo_id, const char *action)
{
	pthread_mutex_lock(&global->monitoring_mutex);
	printf("%zu %d %s\n", current_time_ms() - global->start_time, philo_id, action);
	pthread_mutex_unlock(&global->monitoring_mutex);
}

int	is_eating(t_philo *philo)
{
	//check if still have time with last meal time and start time
	//check se lowest meal == number of meals
	// ve se 'e impar ou par
	//get current time para update do last meal time
	
}

void	fork_locks()
{
	
}

void	philo_meal()
{
	
}