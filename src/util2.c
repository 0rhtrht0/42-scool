/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:11:15 by horandri          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:50 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int is_in(char *tab, char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if (str[i] != tab[i])
            return(0);
        if (str[i] == '=' && tab[i] == '=')
            return(1);
        i++;
    }
    return(0);
}

int indx_in_tab(char **tab, char *str)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (is_in(tab[i], str))
            return(i);
        i++;
    }
    return(-1);
}

int is_in_tab(char **env, char **str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[++i])
    {
        if (indx_in_tab(env, str[i]) >= 0)
            j++;
    }
    return(j);
}
