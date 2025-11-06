/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:48:57 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/06 17:36:23 by yikebata         ###   ########.fr       */
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
			execve_cmd1(av[1], av[2], envp, vars);
		else if (cmd == 2)
			execve_cmd2(av[3], av[4], envp, vars);
	}
	return (pid);
}

int	do_pipex(char **av, char **envp)
{
	t_pipex	vars;

	init_struct(&vars);
	if (pipe(vars.pipe_fds) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	vars->pid1 = fork_cmd(av, envp, &vars, 1);
	if (vars->pid1 == -1)
		return (EXIT_FAILURE);
	vars->pid2 = fork_cmd(av, envp, &vars, 2);
	if (vars->pid2 == -1)
		return (EXIT_FAILURE);
	return (pipe_fd_cleanup(vars));
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
		return (EXIT_FAILURE);
	return (do_pipex(av, envp));
}
