/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:23:47 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 10:03:59 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    char *cmd;
    t_data *data;
    char **temp_env;

    temp_env = export_env(env);
    intitsing(argc, argv);
    while (1)
    {
        cmd = readline("minishell>");
        if (!cmd && write(1, "exit\n", 5))
            break;
        if (*cmd)
        {
            data = NULL;
            if (ft_treatment(cmd, &data, temp_env))
            {
                free_t(temp_env);
                if (execc(&data) < 0 && ft_freecmd(cmd))
                    return (exitt(&data));
                temp_env = export_env(data->var_env);
                free_list(&data);
            }
        }
        free(cmd);
        intitsing(argc, argv);
    }
    free_t(temp_env);
    return (0);
}
