/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:39:39 by horandri          #+#    #+#             */
/*   Updated: 2024/10/25 13:17:41 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char    *ret_aff_equal(char *str)
{
    int i;

    i = 0;
    while (str[i] != '=')
    {
        if (str[i] == '\0')
            return (NULL);
        i++;
    }
    return(str + ++i);
}

char    *get_env(t_data **data, char *str)
{
    int i;

    if (check_exist2(str, (*data)->var_env) == 0)
    {
        i = check_exist(str, (*data)->var_env, ft_strlen(str));
        return(ret_aff_equal((*data)->var_env[i]));
    }
    return(NULL);
}
