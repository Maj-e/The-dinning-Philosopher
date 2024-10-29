/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:14:41 by matteo            #+#    #+#             */
/*   Updated: 2024/10/29 23:35:03 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int start_dinner(t_table *table)
{
    unsigned int    i;
    
    table->start_time = get_time_in_ms() +  (table->number_of_philosophers * 2 * 10);
    i = 0;
    while (i < table->number_of_philosophers)
    {
        if (pthread_create(&table->philos[i]->thread, NULL, &philosopher, table->philos[i]))
            return (error_failure())
    }
}

int main(int ac, char **av)
{
    t_table *table;
    if (ac < 4)
    {
        return(message(PARAMS, NULL, EXIT_FAIL));
    }
    table = set_table(av, ac);
    if (!table)
        return (EXIT_FAIL);
    if (!start_dinner(table))
        return (EXIT_FAIL);

        
    return (0);
}