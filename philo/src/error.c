/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:13:23 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/26 14:30:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	free_fork_locks(t_global *global);

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}


void	ft_exit(t_global *global, int status, const char *message)
{
	if(global != NULL)
	{
		if (global->fork_locks)
			free_fork_locks(global);
		if (global->philos)
			free(global->philos);
		pthread_mutex_destroy(&global->data_mutex);
		pthread_mutex_destroy(&global->monitoring_mutex);
		pthread_mutex_destroy(&global->dead_flag_mutex);
		free(global);
	}
	if (message)
		write(STDERR_FILENO, message, ft_strlen(message));
	exit(status);
}

static void	free_fork_locks(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_mutex_destroy(&global->fork_locks[i]);
		i++;
	}
	free(global->fork_locks);
}
