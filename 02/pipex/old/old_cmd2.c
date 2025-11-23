/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:37:40 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/21 14:24:37 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	do_cmd2(t_pipex *vars, char *cmd_fullpath, char **cmds, char **envp)
{
	dup2(vars->out_fd, STDOUT_FILENO);
	dup2(vars->pipe_fds[0], STDIN_FILENO);
	close_fds(vars->out_fd, vars->pipe_fds);
	execve(cmd_fullpath, cmds, envp);
	cmd_cleanup(&cmds, &cmd_fullpath);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	execve_cmd2(char *file, char *cmd, char **envp, t_pipex *vars)
{
	char	**cmds;
	char	*cmd_fullpath;

	cmds = ft_split(cmd, ' ');
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
	do_cmd2(vars, cmd_fullpath, cmds, envp);
}
