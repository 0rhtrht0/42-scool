/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:10:10 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 11:45:02 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exitt(t_data **data)
{
    int i;

    i = 0;
    if ((*data)->cmd_tab[1] && ft_isalnum_char((*data)->cmd_tab[1]))
    {
        i = ft_atoi((*data)->cmd_tab[1]);
    }
    free_list(data);
    return(i);
}

