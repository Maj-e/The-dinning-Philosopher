/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:14:26 by matteo            #+#    #+#             */
/*   Updated: 2024/10/29 23:14:27 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t *forks;
	unsigned int i;

	forks = malloc(sizeof(pthread_mutex_t) * table->number_of_philosophers);
	if (!forks)
		return (null_error(MALLOC_ERR, NULL, 0));
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (null_error(MUTEX_ERROR, NULL, 0));
		i++;
	}
	return (forks);
}

void	distrib_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id++) % philo->table->number_of_philosophers;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id++) % philo->table->number_of_philosophers;
		philo->fork[1] = philo->id;
	}
}

int	init_mutexes(t_table *table)
{
	table->fork_locks = set_forks(table);
	if (!table->fork_locks)
		return (1);
	if (set_pthread_mutex(&table->sim_stop_lock, 0) != 0)
		return (null_error(MUTEX_ERROR, NULL, table));
}

static t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (!philos)
		return (null_error(MALLOC_ERR, NULL, 0));
	i = 0;
	while (i < table->number_of_philosophers)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (null_error(MALLOC_ERR, NULL, 0));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (null_error(MALLOC_ERR, NULL, 0));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

t_table    *set_table(int ac, char **av)
{
    t_table *table = NULL;

    table->number_of_philosophers = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    table->times_must_eat = -1;
    if (ac == 6)
    {
        table->times_must_eat = ft_atoi(av[5]);
    }
    table->philos = init_philosophers(table);
    if (!table->philos)
        return (NULL);
	if (!init_mutex(table))
		return (NULL);
	table->sim_stop = false;
    return (table);
}
