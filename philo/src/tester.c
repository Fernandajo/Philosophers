
#include "../inc/philo.h"

void	ft_test(t_global *global) {
	printf("Number of philos: %i\n", global->num_of_philo);
	printf("Time to die: %i\n", global->time_to_die);
	printf("Time to eat: %i\n", global->time_to_eat);
	printf("Time to sleep: %i\n", global->time_to_sleep);
	printf("Number of times they need to eat: %i\n", global->number_of_times_must_eat);
	printf("lowest_meal: %d\n", global->lowest_meal);
    printf("dead_flag: %d\n", global->dead_flag);
    printf("start_time: %ld\n", global->start_time);

    for (int i = 0; i < global->num_of_philo; i++) {
        t_philo *philo = &global->philos[i];
        printf("\nPhilo %d:\n", i + 1);
        printf("philo_id: %d\n", philo->philo_id);
        printf("eating: %d\n", philo->eating);
        printf("meals_eaten: %d\n", philo->meals_eaten);
        printf("last_meal: %d\n", philo->last_meal);
        printf("local_dead_flag: %d\n", philo->local_dead_flag);
        printf("local_lowest_meal: %d\n", philo->local_lowest_meal);
	}
}
