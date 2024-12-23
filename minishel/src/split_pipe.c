/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:40:00 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:34:54 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void initsplit(t_split **temp, int *i, int *j)
{
    *i = 0;
    *j = 0;
    *temp = NULL;
}


static void add_str(t_split **tete, int start, int end, char *str)
{
    t_split *temp;
    t_split *tpm;
    int len;
    char *tempstr;

    temp = NULL;
    temp = malloc(sizeof(t_split));
    len = end - start + 1;
    tempstr = ft_substr(str, start, len);
    temp->line = ft_strtrim(tempstr, " ");
    temp->next = NULL;
    free(tempstr);
    if ((*tete) == NULL || tete == NULL)
    {
        *tete = temp;
        return ;   
    }
    tpm = NULL;
    tpm = *tete;
    while(tpm->next != NULL)
        tpm = tpm->next;
    tpm->next = temp;
}

static void free_split(t_split **tete)
{
    t_split *temp;

    temp = NULL;
    while (*tete != NULL)
    {
        temp = NULL;
        temp = (*tete)->next;
        free((*tete)->line);
        free(*tete);
        *tete = temp;
    }
}

static char **ret_splt(t_split **tete, int i)
{
    char **tab;
    t_split    *temp;

    temp = NULL;
    temp = *tete;
    tab = malloc(sizeof(char *) * i);
    i = 0;
    while (temp)
    {
        tab[i] = ft_strdup(temp->line);
        i++;
        temp = temp->next;
    }
    tab[i] = NULL;
    free_split(tete);
    return(tab);
}



char    **split_pipe(char  *str)
{
    t_split *temp;
    int compt;
    int start;
    char c;

    initsplit(&temp, &compt, &start);
    while (1)
    {
        if (str[compt] == 34 || str[compt] == 39)
        {
            c = str[compt++];
            while (str[compt] != c && str[compt] != '\0')
                compt++;
        }
        if (str[compt] == '\0' ||  str[compt] == '|')
        {
            add_str(&temp, start, compt - 1, str);
            start = compt + 1;
        }
        if (str[compt] == '\0')
            break;
        compt++;
    }
    return(ret_splt(&temp, size_split(&temp)));    
}
