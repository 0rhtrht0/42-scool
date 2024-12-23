/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:09:15 by horandri          #+#    #+#             */
/*   Updated: 2024/12/22 12:24:58 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int  egual_is_here(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '=')
            return(1);
        i++;
    }
    return(0);
}

int     nbr_egual(char **tab)
{
    int indx;
    int i;

    i = 1;
    indx = 0;
    while(tab[i])
    {
        if (egual_is_here(tab[i]))
            indx++;
        i++;
    }
    return(indx);
}

void    put_strr(char **tab, char str)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (tab[i][0] == str)
        {
            ft_putstr_fd(tab[i], 1);
            ft_putchar_fd('\n', 1);
        }
        i++;
    }
}

void put_expo(char **tab)
{
    char    chr;
    char    chr2;

    chr = 'A';
    chr2 = 'a';
    while (chr <= 'Z')
    {
        put_strr(tab, chr);
        put_strr(tab, chr2);
        chr++;
        chr2++;
    }
    put_strr(tab, '_');
}

void export(t_data **data)
{
    char **temp_env;
    int     i;
    int coumpt;

    if  (!(*data)->cmd_tab[1])
        put_expo((*data)->var_env);
    temp_env = export_env((*data)->var_env);
    i  = size_tab(temp_env) + nbr_egual((*data)->cmd_tab) - is_in_tab(temp_env, (*data)->cmd_tab);
    free_t((*data)->var_env);
    (*data)->var_env = malloc(sizeof(char *) * (i + 1));
    i = -1;
    coumpt = 0;
    while (temp_env[++i])
        if (indx_in_tab((*data)->cmd_tab, temp_env[i]) < 0)
            (*data)->var_env[coumpt++] = ft_strdup(temp_env[i]);
    i  = size_tab(temp_env) - is_in_tab(temp_env, (*data)->cmd_tab);
    coumpt = 0;
    free_t(temp_env);
    while ((*data)->cmd_tab[++coumpt])
        if (egual_is_here((*data)->cmd_tab[coumpt]))
            (*data)->var_env[i++] = ft_strdup((*data)->cmd_tab[coumpt]);
    (*data)->var_env[i] = NULL;
}
