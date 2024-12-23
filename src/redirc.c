/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:58:46 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:24:54 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void rredir(t_data **data)
{
    t_redir *temp;

    temp = (*data)->redir;
    while(temp)
    {
        if (temp->type == 2)
        {
            heardock(&temp);
        }
        temp = temp->next;
    }  
    ex_red(data);
}

void heardock(t_redir **redir)
{
    char *line;
    t_redir *temp;
    int fd;

    temp = *redir;
    if (temp && (temp)->file == NULL && ft_perror("parse error near `\n'", 1))
        return;
    line = NULL;
    while(1)
    {
        fd = open("src/temp", O_CREAT | O_WRONLY | O_APPEND, 0644);
        line = readline("> ");
        if (line == NULL)
            break;
        if (!ft_strncmp(line, temp->file, ft_strlen(temp->file)) &&
             free_str(line))
            break;
        else
            ft_putendl_fd(line, fd);
        free(line);
    }
    close (fd);
    fd = open("src/temp", O_RDONLY);
    dup2(fd, STDIN_FILENO);
}



void    ex_red(t_data **data)
{
    t_data *t;
    int idx;
    int fd;
    
    t = *data;
    while (t->redir)
    {
        idx = t->redir->type;
        if (three_or_four(t->redir->file, &fd, idx) == 0)
            return ;
        t->redir = t->redir->next;
    }
}
