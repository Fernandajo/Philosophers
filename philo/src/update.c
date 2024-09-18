/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:26:38 by fjoestin          #+#    #+#             */
/*   Updated: 2024/09/18 20:07:26 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	update(t_global *global, int philo_id, const char *action)
{
	pthread_mutex_lock(&global->dead_flag_mutex);
	if (global->dead_flag != DEAD)
	{
		printf("%zu %d %s\n", get_current_time() - 
			global->start_time, philo_id, action);
	}
	pthread_mutex_unlock(&global->dead_flag_mutex);
}

void	is_eating(t_philo *philo)
{
	long    time_diff;


	time_diff = get_time_diff(philo->global->start_time);
	if ((time_diff - philo->last_meal) > philo->global->time_to_die)
	{
		pthread_mutex_lock(&philo->global->dead_flag_mutex);
		philo->local_dead_flag = DEAD;
		pthread_mutex_unlock(&philo->global->dead_flag_mutex);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	else
	{
		update(philo->global, philo->philo_id, EAT);
		philo->last_meal = get_time_diff(philo->global->start_time);
		ft_usleep(philo->global->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(&philo->global->data_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->global->data_mutex);
	}
	return ;
}

int	is_taking_the_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		update(philo->global, philo->philo_id, FORK);
		pthread_mutex_lock(philo->left_fork);
		update(philo->global, philo->philo_id, FORK);
	}
	else
	{
		if (only_one(philo))
			return (1);
		if (philo->meals_eaten == 0)
			ft_usleep(philo->global->time_to_eat);
		pthread_mutex_lock(philo->left_fork);
		update(philo->global, philo->philo_id, FORK);
		pthread_mutex_lock(philo->right_fork);
		update(philo->global, philo->philo_id, FORK);
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
	if (philo->global->time_to_die > philo->global->time_to_sleep + 
		philo->global->time_to_eat	&& dead_loop(philo) == 0)
		update(philo->global, philo->philo_id, THI);
}
