/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:22:33 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 11:16:48 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int three_or_four(char *file, int *fd, int type)
{
    if (type == 3)
        *fd = open(file, O_CREAT | O_WRONLY, 0644);
    else if (type == 4)
        *fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
    else if (type == 1)
    {
        *fd = open(file, O_RDONLY);
        if (*fd < 0 && ft_perror("no such file or directory", 1))
            return(0);
        dup2(*fd, STDIN_FILENO);
        return (1);
    }
    if (*fd < 0)
    {
        perror("open");
        return(0);
    }
    else
    {
        dup2(*fd, STDOUT_FILENO);
        return(1);
    }
}
