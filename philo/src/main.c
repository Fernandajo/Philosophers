/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:51:15 by fjoestin          #+#    #+#             */
/*   Updated: 2024/07/30 14:47:12 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
	t_global global;

	if(argc != 5 && argc != 6)
		error_exit(ERR_ARGS);
	if(!init_global(argc, argv, &global))
		error_exit(ERR_INI);
	
	//ft_test(&global);
	ft_free_mutex(&global);
	return (0);
}
