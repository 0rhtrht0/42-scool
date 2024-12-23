/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:40:31 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 12:14:05 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data    *initparam(t_data **data, int *prev_fd, int *status, int *d, int *d1)
{
    *d = dup(0);
    *d1 = dup(1);
    *prev_fd = 0;
    *status = 0;
    return(*data);
}

void restore(int *restore_fd, int *restore_fd1)
{
    dup2(*restore_fd, 0);
    dup2(*restore_fd1, 1);
}

int    in_out(t_data **temp, int *prev_fd, int *pipe_fd)
{   
    if (*prev_fd != 0) 
    {
        dup2(*prev_fd, STDIN_FILENO);
        close(*prev_fd);
    }
    if ((*temp)->next != NULL) 
    {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
    }
    if ((*temp)->next != NULL) 
    {
        close(pipe_fd[1]);
    }
    return(1);
}

void after_waiting(t_data *temp, int *prev_fd, int *pipe_fd , int *status)
{
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    waitpid(temp->pid, status, 0);
    *status = *status >> 8; 
    if (*prev_fd != 0)
        close(*prev_fd);
    if (temp->next != NULL) 
    {
        *prev_fd = pipe_fd[0];
        close(pipe_fd[1]); 
    }
    if (temp->fd_out)
        close (temp->fd_out);
}

int return_aft_exec(int status, int *prev_fd)
{
    if (*prev_fd != 0)
        close(*prev_fd);
    if (access("src/temp", F_OK) != -1)
        unlink("src/temp");
    return (status); 
}
