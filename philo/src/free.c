/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:13:14 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/28 17:56:33 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_free_mutex(t_global *global)
{
	for (int i = 0; i < global->num_of_philo; i++) {
	        pthread_mutex_destroy(&global->fork_locks[i]);
	    }
	    free(global->fork_locks);
	    free(global->philos);
	
	    pthread_mutex_destroy(&global->philo_meal_mutex);
	    pthread_mutex_destroy(&global->monitoring_mutex);
}