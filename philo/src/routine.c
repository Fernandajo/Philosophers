/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:39 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/22 20:23:18 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philosophers(t_global *global);
static void *monitor(void *arg);

static void	*philo_routine(void *arg) //comer dormir pensar
{
	t_philo	*philo = (t_philo *)arg;
	t_global *global = philo->global;
	
	while (1)
	{
/* 		if (global->dead_flag == DEAD)
			break; */
		if (is_eating(philo))
			continue;
		is_sleeping(philo);
		update(global, philo->philo_id, THI);
	}
	return (0);
}

void	init_philosophers(t_global *global)
{
	int	i;

	i = 0;
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
	//pthread_join(global->monitor, NULL);
}

void	init_monitor(t_global *global)//checar por meals eaten and dead
{
	if (pthread_create(&global->monitor, NULL, &monitor, &global) != 0)
		ft_exit(global, 1, ERR_INI);
}

static void *monitor(void *arg)
{
	t_global *global = (t_global *)arg;
	int	i;
	int	j;
	int	all_ate;

	i = 0;
	all_ate = 1;
	j = 0;
    while (!global->dead_flag)
	{
        while(i < global->num_of_philo)
		{
            t_philo *philo = &global->philos[i];

            if (!philo->eating && ((int)get_current_time() - philo->last_meal > global->time_to_die)) {
                update(global, philo->philo_id, DIE);
                global->dead_flag = 1;
                break;
            }
			i++;
        }

        while (j < global->num_of_philo) 
		{
            if (global->number_of_times_must_eat != -1 && global->philos[i].meals_eaten < global->number_of_times_must_eat) {
                all_ate = 0;
                break;
            }
        }
        if (all_ate) {
            global->dead_flag = 1;
        }
    }
    return (0);
}