/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:51:15 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/26 13:38:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
	t_global *global;

	global = NULL;
	if(argc != 5 && argc != 6)
		ft_exit(global, 1, ERR_ARGS);
	global = init_global(argc, argv, global);
	init_routine(global);
	monitor(global);
	join_threads(global);
	ft_exit(global, 1, 0);
	return (0);
}
