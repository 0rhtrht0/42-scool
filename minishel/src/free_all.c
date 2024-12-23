/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:45:05 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 08:28:47 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_freecmd(char *str)
{
    free(str);
    return (1);
}

void intitsing(int ac, char **av)
{
    (void)ac;
    (void)av;
    signal(SIGINT, sig_c);
    signal(SIGQUIT, SIG_IGN);  
}

int size_split(t_split **tete)
{
    t_split *temp;
    int i;

    temp = NULL;
    temp = *tete;
    i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    i = i + 1;
    return(i);
}

int cmd_ok(char *str)
{
    int i;

    if (str == NULL)
        return(0);
    i = 0;
    while(str[i])
    {
        if (str[i] != 32 && str[i] != 9)
            return(1);
        i++;
    }
    return(0);
}