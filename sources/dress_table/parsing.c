/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:14:34 by matteo            #+#    #+#             */
/*   Updated: 2024/10/29 23:42:05 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
            return (1);
		i++;
	}
	return (0);
}

int check_inputs(int count, char **input)
{
    int i;
    int nb;

    i = 1;
    while (i < count)
    {
        if (!digit_check(input[i]))
            return (message(DIGIT_INPUT_ERROR, input[i], FAILURE));
        nb = ft_atoi(input[i]);
        if (i == 1 && (nb <= 0 || nb > PHILO_MAX))
            return (message(ERROR_INPUT_FLOW, PHILO_MAX_STR, FAILURE));
        if (i != 1 && nb == -1)
			return (msg(DIGIT_INPUT_ERROR, input[i], false));
		i++;
    }
    return(0);
}