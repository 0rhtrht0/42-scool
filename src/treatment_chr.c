/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:26:07 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:36:16 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char    **export_env(char **env)
{
    int i;
    char    **env_ret;

    i = 0;
    while(env[i])
        i++;
    env_ret = (char **)malloc (sizeof(char *) * (i + 1));
    i = 0;
    while (env[i])
    {
        env_ret[i] = ft_strdup(env[i]);
        i++;
    }    
    env_ret[i] = NULL;
    return(env_ret);
}

int ft_treatment(char *src, t_data **data, char **env)
{
    char    **out;
    int     i;

    if (cmd_ok(src) == 0)
        return(0);
    add_history(src);
    out = split_pipe(src);
    i = -1;
    while (out[++i] != NULL)
        ft_inser_back(data, out[i], env);
    free_t(out);
    src = NULL;
    return(1);
}

 char    *ft_sum_char(char *s1, char *s2)
{
    char    *retrn;
    
    retrn = ft_strdup(s1);
    if (!retrn)
        return(NULL);
    retrn = ft_strjoin(retrn, "/");
    if (!retrn)
        return(NULL);
    retrn = ft_strjoin(retrn, s2);
    if (!retrn)
        return(NULL);
    return (retrn);
}
