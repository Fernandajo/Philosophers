
#include "../inc/philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	error_exit(const char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(1);
}