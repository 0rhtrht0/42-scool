/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:09:01 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:26:59 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_pwd(t_data **data)
{
	char cwd[2048];

	if ((*data)->cmd_tab[1] == NULL)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			ft_putstr_fd(cwd, 1);
			ft_putchar_fd('\n', 1);
		}
		else
		{
			perror("pwd");
		}
	}
}

void treament_env(t_data **data, char *old_pwd, char *pwd)
{
	int i;

	i = -1;
	while ((*data)->var_env[++i])
	{
		if (ft_strncmp((*data)->var_env[i], "PWD", 3) == 0)
		{
			free((*data)->var_env[i]);
			(*data)->var_env[i] = ft_strdup("PWD=");
			(*data)->var_env[i] = ft_strjoin((*data)->var_env[i], pwd);
		}
	}
	i = -1;
	while ((*data)->var_env[++i])
	{
		if (ft_strncmp((*data)->var_env[i], "OLDPWD", 6) == 0)
		{
			free((*data)->var_env[i]);
			(*data)->var_env[i] = ft_strdup("OLDPWD=");
			(*data)->var_env[i] = ft_strjoin((*data)->var_env[i], old_pwd);
		}
	}
}

int ft_cd(t_data **data)
{
	char old_pwd[2024];
	char pwd[2024];
	char *home;

	getcwd(old_pwd, sizeof(old_pwd));
	if ((*data)->cmd_tab[1] == NULL || ft_strncmp((*data)->cmd_tab[1], "~", 2) == 0)
	{
		free_t((*data)->cmd_tab);
		home = ft_strdup("cd ");
		home = ft_strjoin(home, get_env(data, "HOME"));
		(*data)->cmd_tab = ft_split(home, 32);
		free(home);
	}
	if (chdir((*data)->cmd_tab[1]) != 0)
		perror("cd");
	getcwd(pwd, sizeof(pwd));
	treament_env(data, old_pwd, pwd);
	return (1);
}

int  put_env(t_data **data)
{
	int i;
	t_data *temp;

	i = 0;
	temp = *data;
	while (temp->var_env[i])
	{
		ft_putstr_fd(temp->var_env[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	return (1);
}
