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


typedef struct s_philo {
	
	int		philo_id;
}	t_philo;

typedef struct s_global {
	
	int num_of_philo;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
}	t_global;

#endif