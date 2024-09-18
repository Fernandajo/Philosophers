/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:00:20 by fjoestin          #+#    #+#             */
/*   Updated: 2024/09/18 20:00:23 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->dead_flag_mutex);
	if (philo->global->dead_flag == DEAD)
	{
		pthread_mutex_unlock(&philo->global->dead_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->dead_flag_mutex);
	return (0);
}

int dead_loop_global(t_global *global)
{
	pthread_mutex_lock(&global->dead_flag_mutex);
	if (global->dead_flag == DEAD)
	{
		pthread_mutex_unlock(&global->dead_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&global->dead_flag_mutex);
	return (0);
}