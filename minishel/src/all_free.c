/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:09:15 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:03:28 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    free_t(char **src)
{
    int     i;

    if (src[0] == NULL)
        return;
    i = 0;
    while(src[i])
    {
        free (src[i]);
        i++;
    }
    free (src);
    src = NULL;
}

void    free_redir(t_redir **redir)
{
    t_redir *temp;

    temp = NULL;
    while (*redir != NULL)
    {
        temp = NULL;
        temp = (*redir)->next;
        free((*redir)->file);
        free(*redir);
        *redir = temp;
    }
    
}

void    free_list (t_data **data)
{
    t_data *temp;

    temp = NULL;
    while (*data != NULL)
    {
        temp = NULL;
        temp = (*data)->next;
        if ((*data)->cmd)
            free ((*data)->cmd);
        if ((*data)->cmd_tab)
            free_t((*data)->cmd_tab);
        (*data)->cmd_tab = NULL;
        free_t((*data)->var_env);
        (*data)->var_env = NULL;
        if ((*data)->redir)
            free_redir(&(*data)->redir);
        (*data)->redir = NULL;
        free (*data);
        *data = temp;
    }
}

void    put_tab(char **str)
{
    int i;

    if (!str[0])
        ft_putstr_fd("NULL\n", 1);
    i = 0;
    while (str[i])
    {
        ft_putstr_fd(str[i], 1);
        ft_putchar_fd('\n', 1);
        i++;
    }
}

int size_tab(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}
