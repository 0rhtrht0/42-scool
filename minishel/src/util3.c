/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:04:25 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:58:37 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int get_singal(int i)
{
    if(i == 1)
    {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
    }
    else if (i == 2)
    {
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
    }
    else if (i == 3)
    {
        signal(SIGINT, sig_c);
        signal(SIGQUIT, SIG_IGN);
    }
    return(1);
}

void after_wt(int  *i, int pid)
{
    waitpid(pid, i, 0);
    if (WIFSIGNALED(*i))
    {
        if (WTERMSIG(*i) == SIGQUIT)
            write(1, "Quit (core dumped)\n", 19);
        else if (WTERMSIG(*i) == SIGINT)
            write (1, "\n", 1);
    }
    get_singal(3);
}

int free_str(char *str)
{
    if (str)
        free(str);
    return(1);
}

char *ft_perror_str(char *str)
{
    perror(str);
    return(NULL);
}