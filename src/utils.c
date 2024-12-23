/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:27:37 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 15:59:48 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    aff(int i)
{
    char    u;

    if (i == 0)
        write(1, "eto\n", 4);
    else if (i == 1)
        write(1, "\n", 1);
    else if (i == 2)
        write(1, ">>>", 3);
    else if (i == 3)
        while (i)
        {
            u = i + '0';
            write(1, &u, 1);
            i--;
        }
    else
        write(1, "\n", 1);
}

void nbr(int i)
{
    ft_putnbr_fd(i, 1);
    write(1, "\n", 1);
}

int ft_perror(char *str, int i)
{
    perror(str);
    return(i);
}

static int ckcc2(char *str)
{
    if(ft_strncmp("cd", str, ft_strlen(str)) == 0)
        return(2);
    else if(ft_strncmp("exit", str, ft_strlen(str)) == 0)
        return(2);
    else if(ft_strncmp("unset", str, ft_strlen(str)) == 0)
        return(2);
    else if(ft_strncmp("export", str, ft_strlen(str)) == 0)
        return(2);
    else if(ft_strncmp("env", str, ft_strlen(str)) == 0)
        return(1);
    else if(ft_strncmp("echo", str, ft_strlen(str)) == 0)
        return(1);
    else if(ft_strncmp("pwd", str, ft_strlen(str)) == 0)
        return(1);
    else
        return(0);
}

int cb(char *str)
{
    int i;
    
    i = ckcc2(str);
    return(i);
}

