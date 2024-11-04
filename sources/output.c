/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 03:24:31 by matteo            #+#    #+#             */
/*   Updated: 2024/10/30 04:47:11 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    write_status(t_philo *philo, bool reaper_report, t_status status)
{
    
}

void    write_outcome(t_table *table)
{
    unsigned int    i;
    unsigned int    full_count;

    i = 0;
    full_count = 0;
    while (i < table->number_of_philosophers)
    {
        if (table->philos[i]->times_ate >= (unsigned int)table->times_must_eat)
            full_count++;
        i++;
    }
    pthread_mutex_lock(&table->write_lock);
    printf("%d/%d philosophers had at least %d meals.\n", full_count, table->number_of_philosophers, table->times_must_eat);
    pthread_mutex_unlock(&table->write_lock);
    return ;
}