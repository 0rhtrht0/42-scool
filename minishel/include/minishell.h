/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:51:45 by horandri          #+#    #+#             */
/*   Updated: 2024/12/23 14:57:34 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <unistd.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

typedef struct s_redir
{
    int type;
    char *file;
    struct s_redir *next;
} t_redir;


typedef struct s_data
{
    int fd_in;
    int fd_out;
    char *cmd;
    char **cmd_tab;
    char *home;
    struct s_data *next;
    bool after;
    char **var_env;
    int compt;
    bool herdoc_ishere;
    int ret_build;
    t_redir *redir;
    pid_t   pid;
} t_data;

typedef struct s_ex
{
    t_data *temp;
    int pipe_fd[2];
    int prev_fd;
    int r_fd;
    int r_fd1;
    int status;
} t_ex;

typedef struct s_split
{
    char    *line;
    struct s_split *next;
} t_split;


int main(int argc, char **argv, char **env);
void ft_pwd(t_data **data);
int ft_treatment(char *src, t_data **data, char **env);
char *ret_funstr(t_data *data, char *str);
void treament_env(t_data **data, char *old_pwd, char *pwd);
int ft_chk_error_cmd(char **src);
void free_t(char **src);
int put_env(t_data **data);
void ft_echo(t_data **data);
int ft_cd(t_data **data);
char **export_env(char **env);
char *ft_sum_char(char *s1, char *s2);
void ft_unset(t_data **data, char **str);
void free_list(t_data **data);
int track_redir(char **tab);
void put_tab(char **str);
void ft_inser_back(t_data **tete, char *str, char **env);
int size_lst(t_data **data);
int size_tab(char **str);
void free_all_env(t_data **data);
void aff(int i);
int check_exist(char *str, char **tab, int size);
char *get_dollar(char *str);
int     execc(t_data **data);
int check_exist2(char *str, char **tab);
char *get_env(t_data **data, char *str);
void export(t_data **data);
int indx_in_tab(char **tab, char *str);
int is_in_tab(char **env, char **str);
int ft_perror(char *str, int i);
int cb(char *str);
void nbr(int i);
int    execute_build(t_data **data);
t_data    *initparam(t_data **data, int *prev_fd, int *status, int *d, int *d1);
int   in_out(t_data **temp, int *prev_fd, int *pipe_fd);
void after_waiting(t_data *temp, int *prev_fd, int *pipe_fd , int *status);
int return_aft_exec(int status, int *prev_fd);
int execute_command(t_data **data); 
int exitt(t_data **data);
char  **retsplit(char *str);
int ft_freecmd(char *str);
int cmd_ok(char *str);
int size_split(t_split **tete);
char    **split_pipe(char  *str);
//redir
int    track_r2(char *tab);
int    track_r1(char *tab);
char **finaltab(t_data **data, char **tab);
int redd(char *str);
void    ex_red(t_data **data);
void restore(int *restore_fd, int *restore_fd1);
void heardock(t_redir **redir);
void rredir(t_data **data);
int three_or_four(char *file, int *fd, int type);
//
int handle_input_redirection(char *file);
int handle_output_redirection(char *file, int append);
int handle_heredoc(char *delimiter);
int handle_redirection(char **cmd_tab);
int execute_redirection(t_data *data);
// int	ft_strcmp(char *s1, char *s2);
void intitsing(int ac, char **av);
int cmd_ok(char *str);
//signal
void sig_c(int sig);
int get_singal(int i);
void after_wt(int  *i, int pid);

char **finaltab(t_data **data, char **tab);
int free_str(char *str);
char *ft_perror_str(char *str);

#endif
