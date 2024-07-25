
#include "../inc/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int is_number(const char *str) 
	{
    if (*str == '\0') {
        return 0;
    }
    while (*str) {
        if (!ft_isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
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
		error_exit(ERR_MAX);
	return (result * sign);
}