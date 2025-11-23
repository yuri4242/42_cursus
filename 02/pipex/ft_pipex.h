/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:49:25 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/23 18:09:18 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define ENV_PATH_KEY "PATH="
# define CMD_NOT_FOUND 127
# define NORMAL 0
# define S_QUOTE 1
# define D_QUOTE 2

typedef struct s_pipex
{
	int		pipe_fds[2];
	int		in_fd;
	int		out_fd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

//ft_pipex.c
int		main(int ac, char **av, char **envp);
int		do_pipex(char **av, char **envp);
pid_t	fork_cmd(char **av, char **envp, t_pipex *vars, int cmd);

//cmd1.c
void	execve_cmd(int nbr, char *cmd, char **envp, t_pipex *vars);
void	do_cmd1(t_pipex *vars, char *cmd_fullpath, char **cmds, char **envp);
void	do_cmd2(t_pipex *vars, char *cmd_fullpath, char **cmds, char **envp);

//split_cmds1.c
char	**split_cmds(const char *cmd_str);

//split_cmds2.c
void	state_parser(char c, int *state);

//utils1.c
void	init_struct(t_pipex *vars);
int		pipe_fd_cleanup(t_pipex vars);
void	cmd_cleanup(char ***arr, char **str);
void	close_fds(int file_fd, int *fds);
void	free_all(char **arr);

//utils2.c
char	*create_cmd_path(char *cmd, char **envp);
void	print_error(char *err);
void	close_all_fds(t_pipex *vars);

#endif
