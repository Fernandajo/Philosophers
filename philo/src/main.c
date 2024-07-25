/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:51:15 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/21 18:21:13 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
	t_global global;

	if(argc != 5 && argc != 6)
		error_exit(ERR_ARGS);
	if(init_philo(argc, argv, &global))
		error_exit(ERR_INI);
	printf("Number of philos: %i\n", global.num_of_philo);
	printf("Time to die: %i\n", global.time_to_die);
	printf("Time to eat: %i\n", global.time_to_eat);
	printf("Time to sleep: %i\n", global.time_to_sleep);
	printf("Number of times they need to eat: %i\n", global.number_of_times_each_philosopher_must_eat);

	return (0);
}
