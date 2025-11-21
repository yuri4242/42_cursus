/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:48:57 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/21 14:38:32 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

pid_t	fork_cmd(char **av, char **envp, t_pipex *vars, int cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (cmd == 1)
			execve_cmd(cmd, av[2], envp, vars);
		else if (cmd == 2)
			execve_cmd(cmd, av[3], envp, vars);
	}
	return (pid);
}

int	file_open(char *infile, char *outfile, t_pipex *vars)
{
	vars->in_fd = open(infile, O_RDONLY);
	if (vars->in_fd == -1)
	{
		perror(infile);
		return (EXIT_FAILURE);
	}
	vars->out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->out_fd == -1)
	{
		perror(outfile);
		close(vars->in_fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	do_pipex(char **av, char **envp)
{
	t_pipex	vars;

	init_struct(&vars);
	if (file_open(av[1], av[4], &vars) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pipe(vars.pipe_fds) == -1)
	{
		perror("pipe");
		close(vars.in_fd);
		close(vars.out_fd);
		return (EXIT_FAILURE);
	}
	vars.pid1 = fork_cmd(av, envp, &vars, 1);
	if (vars.pid1 == -1)
	{
		close_all_fds(&vars);
		return (EXIT_FAILURE);
	}
	vars.pid2 = fork_cmd(av, envp, &vars, 2);
	if (vars.pid2 == -1)
	{
		close_all_fds(&vars);
		return (EXIT_FAILURE);
	}
	return (pipe_fd_cleanup(vars));
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		write(2, "Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 46);
		return (EXIT_FAILURE);
	}
	return (do_pipex(av, envp));
}
