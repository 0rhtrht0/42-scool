/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treament_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:25:50 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:47:19 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void	ft_inser_back(t_data **tete, char *str, char **env)
{
	t_data	*temp;
	t_data	*point;
	char **tab;

	temp = malloc(sizeof(t_data));
	while (!temp) 
		return ;
    temp->var_env = export_env(env);
	temp->herdoc_ishere = false;
    tab = retsplit(str);
	temp->cmd_tab = finaltab(&temp, tab);	
    temp->cmd = ft_strdup(temp->cmd_tab[0]);
	free_t(tab);
	temp->next = NULL;
	if (*tete == NULL || tete == NULL)
	{
		*tete = temp;
		return ;
	}
	point = NULL;
	point = *tete;
	while (point->next != NULL)
		point = point->next;
	point->next = temp;
}

int     size_lst(t_data **data)
{
    t_data *temp;
    int     i;

    temp = *data;
    i = 0;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return(i);
}

void	free_all_env(t_data	**data)
{
	t_data	*temp;

	temp = *data;
	while (temp)
	{
		free_t(temp->var_env);
		temp->var_env = NULL;
		temp = temp->next;
	}	
}