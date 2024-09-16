/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:29:31 by fjoestin          #+#    #+#             */
/*   Updated: 2024/09/16 15:29:46 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_global	*global;

	global = NULL;
	if (argc != 5 && argc != 6)
		ft_exit(global, 1, ERR_ARGS);
	global = init_global(argc, argv, global);
	init_routine(global);
	monitor(global);
	join_threads(global);
	ft_exit(global, 1, 0);
	return (0);
}
