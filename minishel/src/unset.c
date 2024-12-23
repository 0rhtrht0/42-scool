/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:46:38 by horandri          #+#    #+#             */
/*   Updated: 2024/12/22 12:18:14 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int check_exist(char *str, char **tab, int size)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (ft_strncmp(tab[i], str, size) == 0)
            return (i);
        i++;
    }
    return (-1);
}

static int check_number(char **env, char **tab)
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (tab[i])
    {
        if (check_exist(tab[i], env, ft_strlen(tab[i])) > 0)
            j++;
        i++;
    }
    return (j);
}

int    check_exist2(char *str, char **tab)
{
    int   i;

    i = 1;
    while (tab[i])
    {
        if (ft_strncmp(str, tab[i], ft_strlen(tab[i])) == 0)
            return(1);
        i++;
    }
    return(0);
}

static char **delete_line_env(char **env, t_data **data)
{
    char **temp_env;
    int i;
    int j;

    i = check_number(env, (*data)->cmd_tab);
    if (i == 0)
        return (NULL);
    temp_env = malloc(sizeof(char *) * (size_tab(env) - i + 1));
    i = 0;
    j = 0;
    while (env[i])
    {
        if (check_exist2(env[i], (*data)->cmd_tab) == 0)
            temp_env[j++] = ft_strdup(env[i]);
        i++;
    }
    temp_env[j] = NULL;
    return (temp_env);
}

void ft_unset(t_data **data, char **env)
{
    char **temp_env;
    t_data *temp_lst;
    char **temp;

    if ((*data)->cmd_tab[1] == NULL)
        perror("unset");
    temp_env = export_env(env);
    if (delete_line_env(temp_env, data) == NULL)
        return;
    temp = delete_line_env(temp_env, data);
    free_t(temp_env);
    free_all_env(data);
    temp_lst = *data;
    while (temp_lst)
    {
        temp_lst->var_env = export_env(temp);
        temp_lst = temp_lst->next;
    }
    free_t(temp);
}
