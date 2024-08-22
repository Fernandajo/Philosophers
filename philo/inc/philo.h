/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:17:12 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/22 20:07:46 by fjoestin         ###   ########.fr       */
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
# define ERR_INI "Error: initializing Thread\n"
# define ERR_JOI "Error: Joining Thread\n"
# define ERR_MUT "Error: Initializing mutex\n"

# define EAT "is eating"
# define THI "is thinking"
# define LFORK "has taken the left fork"
# define RFORK "has taken the right fork"
# define SLE "is sleeping"
# define DIE "died"

# define ALIVE 0
# define DEAD 1

typedef struct s_philo {
	pthread_t		thread;
	int				philo_id;
	int				eating;
	int				meals_eaten;
	int				last_meal;
	int				local_dead_flag;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_global	*global;
}	t_philo;

typedef struct s_global {
	pthread_t		monitor;
	int				num_of_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				number_of_times_must_eat;
	int				dead_flag;
	time_t			start_time;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	monitoring_mutex;
	pthread_mutex_t	*fork_locks;
	t_philo			*philos;
}					t_global;


//Error
int		ft_strlen(const char *str);
void	ft_exit(t_global *global, int status, const char *message);


//Utils
int		is_number(const char *str);
long	ft_atoi_philo(const char *str);
int		ft_isdigit(int c);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

//init_philo
int		init_global(int argc, char **argv, t_global *global);
int		check_numbers(int argc, char **argv);
int		init_mutex(t_global *global);
int		init_philo(t_global *global);

// update
void	update(t_global *global, int philo_id, const char *action);
int		take_forks(t_philo *philo);
int		is_eating(t_philo *philo);
void	is_sleeping(t_philo *philo);
int		handle_one(t_philo *philo);
// routine
void		init_philosophers(t_global *global);
void		join_threads(t_global *global);
void		init_monitor(t_global *global);


#endif