#include "philo.h"

static t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!philos)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (error_null(STR_ERR_MALLOC, NULL, 0));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

t_table    set_table(int ac, char **av);
{
    t_table table = NULL;

    table->number_of_philosophers = ft_atoi(av[1]);
    table->ft_atoi(time_to_dieav[2]);
    table->ft_atoi(time_to_eat = av[3]);
    table->ft_atoi(time_to_sleep = av[4]);
    table->tumes_must_eat = -1;
    if (ac == 6)
    {
        table->ft_atoi(times_must_eat = av[5]);
    }
    table->philos = init_philosophers(table);
    if (!table->philo)
        return (NULL);
    return (table);
}
