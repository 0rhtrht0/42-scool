/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:51:53 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 16:35:12 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void path_traitment(t_data *data)
{
    char    *bin;
    int i;
    char    **path_spit;
    
    if (data->cmd[0] != '/' && ft_strncmp(data->cmd, "./", 2))
    {
        path_spit = ft_split(get_env(&data, "PATH"), ':');
        i = -1;
        while (path_spit[++i])
        {
            bin = ft_sum_char(path_spit[i], data->cmd);
            if (access(bin, F_OK) == 0)
            {
                free (data->cmd);
                free(data->cmd_tab[0]);
                data->cmd = ft_strdup(bin);
                data->cmd_tab[0] = ft_strdup(bin);
                free(bin);
                return ;
            }
            free(bin);
        }
        free_t(path_spit);
    }
}

int execute_command(t_data **data)
{
    int i;
    int pid;
    if (cb ((*data)->cmd) == 1)
        exit(execute_build(data));
    else
    {
        pid = fork();
        if (pid == 0 && get_singal(1))
        {
            path_traitment(*data);
            if (execve((*data)->cmd, (*data)->cmd_tab,(*data)->var_env) < 0)
                perror("");
            return (1);
        }
        else if (pid > 0 && get_singal(2))
        {
            after_wt(&i, pid);
            return (1);
        }
    }
    return (0);
}

int    execute_build(t_data **data)
{
    if (ft_strncmp((*data)->cmd, "pwd", 4) == 0 && !(*data)->cmd_tab[1])
        ft_pwd(data);
    else if (ft_strncmp((*data)->cmd, "echo", 5) == 0)
        ft_echo(data);
    else if (ft_strncmp((*data)->cmd, "export", 7) == 0)
        export(data);
    else if (ft_strncmp((*data)->cmd, "cd", 3) == 0)
        return(ft_cd(data));
    else if (ft_strncmp((*data)->cmd, "exit", 5) == 0)
        return (-1);
    else if (ft_strncmp((*data)->cmd, "env", 4) == 0)
        return(put_env(data));
    else if (ft_strncmp((*data)->cmd, "unset", 6) == 0)
        ft_unset(data, (*data)->var_env);
    return (15555);
}

int execc(t_data **data) 
{
    t_ex e;     

    e.temp = initparam(data, &e.prev_fd, &e.status, &e.r_fd, &e.r_fd1);
    while (e.temp && e.status >= 0) 
    {
        if (e.temp->herdoc_ishere)
            rredir(&e.temp);
        if (e.temp->redir && e.temp->redir->type != 2)
            ex_red(&e.temp);
        if (e.temp->next != NULL && pipe(e.pipe_fd) == -1) 
            return(ft_perror("pipe", -1));
        if (cb((e.temp)->cmd) == 2 && in_out(&e.temp, &e.prev_fd, e.pipe_fd))
            e.status = execute_build(&e.temp);
        else
        {
            e.temp->pid = fork();
            if (e.temp->pid == 0 && in_out(&e.temp, &e.prev_fd, e.pipe_fd))
                exit(execute_command(&e.temp));
            else if (e.temp->pid > 0)
                after_waiting(e.temp, &e.prev_fd, e.pipe_fd, &e.status);
        }        e.temp = e.temp->next;
        restore(&e.r_fd, &e.r_fd1);
    }
    return(return_aft_exec(e.status, &e.prev_fd));
}

