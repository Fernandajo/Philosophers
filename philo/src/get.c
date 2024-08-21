/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:37:39 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/28 18:00:44 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	get_meal_count(t_global *global, t_philo *philo)
{
	pthread_mutex_lock(&global->philo_meal_mutex);
	global->lowest_meal = lowest_meal_count(&global);
	philo->local_lowest_meal = global->lowest_meal;
	pthread_mutex_unlock(&global->philo_meal_mutex);
}

int	lowest_meal_count(t_global *global)
{
	t_philo	*philo;
	int	lowest;
	int	i;
	
	i = 0;
	philo = global->philos;
	lowest = INT_MAX;
	while(i < global->num_of_philo)
	{
		if(lowest < philo[i].meals_eaten)
			lowest = philo[i].meals_eaten;
		i++;
	}
	return (lowest);
}