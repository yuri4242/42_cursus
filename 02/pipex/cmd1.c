/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:36:38 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/24 00:15:12 by yu-ri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	do_cmd1(t_pipex *vars, char *cmd_fullpath, char **cmds, char **envp)
{
	dup2(vars->in_fd, STDIN_FILENO);
	dup2(vars->pipe_fds[1], STDOUT_FILENO);
	close_fds(vars->in_fd, vars->pipe_fds);
	execve(cmd_fullpath, cmds, envp);
	cmd_cleanup(&cmds, &cmd_fullpath);
	if (errno == EACCES)
	{
		perror("execve");
		exit(126);
	}
	perror("execve");
	exit(EXIT_FAILURE);
}

void	do_cmd2(t_pipex *vars, char *cmd_fullpath, char **cmds, char **envp)
{
	dup2(vars->out_fd, STDOUT_FILENO);
	dup2(vars->pipe_fds[0], STDIN_FILENO);
	close_fds(vars->out_fd, vars->pipe_fds);
	execve(cmd_fullpath, cmds, envp);
	cmd_cleanup(&cmds, &cmd_fullpath);
	if (errno == EACCES)
	{
		perror("execve");
		exit(126);
	}
	perror("execve");
	exit(EXIT_FAILURE);
}

void	execve_cmd(int nbr, char *cmd, char **envp, t_pipex *vars)
{
	char	**cmds;
	char	*cmd_fullpath;

	cmds = split_cmds(cmd);
	if (cmds == NULL || cmds[0] == NULL)
	{
		free_all(cmds);
		exit(EXIT_FAILURE);
	}
	cmd_fullpath = create_cmd_path(cmds[0], envp);
	if (cmd_fullpath == NULL)
	{
		print_error(cmds[0]);
		cmd_cleanup(&cmds, &cmd_fullpath);
		exit(CMD_NOT_FOUND);
	}
	if (nbr == 1)
		do_cmd1(vars, cmd_fullpath, cmds, envp);
	else if (nbr == 2)
		do_cmd2(vars, cmd_fullpath, cmds, envp);
}
