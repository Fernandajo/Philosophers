/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:51:15 by fjoestin          #+#    #+#             */
/*   Updated: 2024/08/22 20:10:17 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
	t_global *global;

	global = NULL;
	if(argc != 5 && argc != 6)
		ft_exit(global, 1, ERR_ARGS);
	if(!init_global(argc, argv, global))
		ft_exit(global, 1, ERR_INI);
	init_philosophers(global);
	init_monitor(global);
	join_threads(global);
	ft_exit(global, 1, 0);
	return (0);
}

