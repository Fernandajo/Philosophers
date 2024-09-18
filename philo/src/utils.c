/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:32:57 by fjoestin          #+#    #+#             */
/*   Updated: 2024/09/18 20:07:48 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(const char *str)
	{
	if (*str == '\0')
	{
		return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

long	ft_atoi_philo(const char *str)
{
	long	result;
	int		i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
	}
	if (((result * sign) > INT_MAX) || ((result * sign) < INT_MIN))
		ft_exit(NULL, 1, ERR_MAX);
	return (result * sign);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

long	get_current_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}


long	get_time_diff(long	start_time)
{
	struct timeval	current_time;
	long			current_time_ms;
	long			ret;

	gettimeofday(&current_time, NULL);
	current_time_ms
		= (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	ret = current_time_ms - start_time;
	return (ret);
}