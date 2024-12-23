/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:53:09 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:19:18 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *get_dollar(char *str)
{
    char    *ret;
    
    if (str[0] == '$')
    {
        ret = str + 1;
        return(ret);
    }
    else
        return(NULL);
}

void ft_echo(t_data **data)
{
    int i = 1;
    int newline = 1;

    if ((*data)->cmd_tab[1] && strcmp((*data)->cmd_tab[1], "-n") == 0)
    {
        newline = 0;
        i = 2;
    }
    while ((*data)->cmd_tab[i])
    {
        if ((*data)->cmd_tab[i][0] == '$')
            ft_putstr_fd(get_env(data, get_dollar((*data)->cmd_tab[i++])), 
                (*data)->fd_out);
        else
        {
            ft_putstr_fd((*data)->cmd_tab[i], (*data)->fd_out);   
            if ((*data)->cmd_tab[i++])
                ft_putchar_fd(' ', (*data)->fd_out);
        }
        if ((*data)->cmd_tab[i])
            ft_putchar_fd(' ', (*data)->fd_out);
    }
    if (newline)
        ft_putchar_fd('\n', (*data)->fd_out);
}

char *ret_funstr(t_data *data, char *str)
{
    int i;
    char *var_value;
    i = 0;
    while (data->var_env[i] != NULL)
    {
        if (ft_strncmp(data->var_env[i], str, ft_strlen(str)) == 0
             && data->var_env[i][ft_strlen(str)] == '=')
        {
            var_value = data->var_env[i] + ft_strlen(str) + 1;
            return (var_value);
        }
        i++;
    }
    return (NULL);
}
