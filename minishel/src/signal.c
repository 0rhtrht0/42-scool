/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:26:53 by horandri          #+#    #+#             */
/*   Updated: 2024/12/15 15:11:07 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void sig_c(int sig)
{
    if (sig == SIGINT)
	{ 
        write(1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 1);
        rl_redisplay();
    }
}

