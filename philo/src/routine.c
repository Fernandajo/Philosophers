/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:39 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/30 14:51:59 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg) //comer dormir pensar
{
	t_philo	*philo = (t_philo *)arg;
	t_global *global = philo->global;
	
	while (!global->dead_flag)
	{
		get_meals_count(global);
		if (is_eating(philo))
		{
			//update + usleep
		}
		
	}
	return (0);
}

void	*monitor(void *arg) //checar por meals eaten and dead
{
    t_global *global = (t_global *)arg;

    return (0);
}