/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:36:38 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/06 17:44:55 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	do_cmd1(t_pipex *vars, char *cmd_fullpath, char **cmds, char **envp)
{
	dup2(vars->in_fd, STDIN_FILENO);
	dup2(vars->pipe_fds[1], STDOUT_FILENO);
	close_fds(vars->in_fd, vars->pipe_fds);
	execve(cmd_fullpath, cmds, envp);
	cmd1_cleanup(&cmds, &cmd_fullpath);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	execve_cmd1(char *file, char *cmd, char **envp, t_pipex *vars)
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
		ft_printf(stderr, "command not found: %s\n", cmds[0]);
		cmd_cleanup(&cmds, &cmd_fullpath);
		exit(127);//ここマジックナンバーでいいのか？
	}
	vars->in_fd = open(file, O_RDONLY);
	if (vars->in_fd == -1)
	{
		perror(file);
		cmd1_cleanup(&cmds, &cmd_fullpath);
		exit(EXIT_FAILURE);
	}
	do_cmd1(vars, cmd_fullpath, cmds, envp);
}
