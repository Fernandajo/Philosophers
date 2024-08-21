/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:13:23 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/28 18:16:14 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	if(global)
	{
		if (global->fork_locks)
			free_fork_locks
		
	}
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(status);
}

static void	free_forks(t_data *data);

void	ft_exit(t_data *data, char *msg, int status)
{
	if (data)
	{
		if (data->forks)
			free_forks(data);
		if (data->philos)
			free(data->philos);
		pthread_mutex_destroy(&data->data_mutex);
		pthread_mutex_destroy(&data->print_mutex);
		free(data);
	}
	if (msg)
		printf("%s", msg);
	exit(status);
}

static void	free_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}