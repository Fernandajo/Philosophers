/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:17:12 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/21 18:24:09 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_ARGS "Error: wrong number of arguments\n"
# define ERR_NUM "Error: numbers are incorrect\n"
# define ERR_MAX "Error: number exceeds int limits\n"
# define ERR_PHI "Error: the number of philosophers should be between 1 and 200"
# define ERR_INI "Error: initializing "

typedef struct s_philo {
	
	int		philo_id;
}	t_philo;

typedef struct s_global {
	
	int num_of_philo;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_global;

//Error
int	ft_strlen(const char *str);
void	error_exit(const char *message);

//Utils
int is_number(const char *str);
long	ft_atoi_philo(const char *str);
int	ft_isdigit(int c);

//init_philo
int	init_philo(int argc, char **argv, t_global *global);

#endif