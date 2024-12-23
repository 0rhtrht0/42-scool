/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirected.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:51:30 by horandri          #+#    #+#             */
/*   Updated: 2024/12/21 14:48:36 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" 

int redd(char *str)
{
    if(ft_strncmp(str, ">>", 2) == 0)
        return(4);
    if(ft_strncmp(str, "<<", 2) == 0)
        return(2);
    if(ft_strncmp(str, "<", 1) == 0)
        return(1 );
    if(ft_strncmp(str, ">", 1) == 0)
        return(3);
    return(-1);
}

int    track_r1(char *tab)
{
    if (!ft_strncmp(tab, "<", 2) ||
           !ft_strncmp(tab, ">", 2) ||
           !ft_strncmp(tab, "<<", 3) ||
           !ft_strncmp(tab, ">>", 3))
       return (1);
    return (0);
}

int    track_r2(char *tab)
{
    if (!ft_strncmp(tab, "<", 1) ||
            !ft_strncmp(tab, ">", 1) ||
            !ft_strncmp(tab, "<<", 2) ||
            !ft_strncmp(tab, ">>", 2))
        return (1);
    return (0);
}
