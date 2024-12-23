/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:40:16 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 15:51:20 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int  chkk(char *src)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while(src[i])
    {
        if (src[i] == 34)
            j++;
        if (src[i] == 39)
            k++;
        i++;
    }
    if (j % 2 != 0 || k % 2 != 0)
    {
        return(0);
    }
    return(1);
}

static char *trt(char *src)
{
    char *str;
    int i;
    int j;
    char c;
    
    i = -1;
    if (chkk(src) == 0)
        return(NULL);
    while (src[++i])
    {
        if (src[i] == 34 || src[i] == 39)
        {
            c = src[i]; 
            while (src[i] != c)
            {
            }
        }
    }
    str = malloc(sizeof(char) * (ft_strlen(src) - 1));
    i = -1;
    j = 0;
    while (src[++i])
        if (src[i] != 34 && src[i] != 39)
            str[j++] = src[i];
    str[j] = '\0';
    return(str);
}

char  **retsplit(char *str)
{
    char **tab;
    char **tab_ret;
    int i;

    tab = ft_split(str, 32);
    i = size_tab(tab);
    tab_ret = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (1)
    {
        if (tab[i] == NULL)
        {
            tab_ret[i] = NULL;
            break;
        }
        tab_ret[i] = trt(tab[i]);
        i++;
    }
    tab_ret[i] = NULL;
    free_t(tab);
    return(tab_ret);
}
