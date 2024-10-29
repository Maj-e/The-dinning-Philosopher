/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:14:44 by matteo            #+#    #+#             */
/*   Updated: 2024/10/29 23:40:30 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error_failure(char *str, char *details, t_table *table)
{
    if (table != NULL)
        free_table(table);
    return (message(str, details, SUCCESS));
}


int message(char *str, char *detail, int exit_type)
{
    if (!detail)
        printf(str, "philo:");
    else
        printf(str, "philo:", detail);
    return (exit_type);
}

void    *null_error(char *str, char *details, t_table *table)
{
    if (table !=  NULL)
        free_table(table);
    message(str, details, EXIT_FAILURE);
    return (NULL);
}