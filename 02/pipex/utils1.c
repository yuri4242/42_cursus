/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:39:10 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/22 18:00:22 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	init_struct(t_pipex *vars)
{
	vars->pipe_fds[0] = -1;
	vars->pipe_fds[1] = -1;
	vars->in_fd = -1;
	vars->out_fd = -1;
	vars->pid1 = -1;
	vars->pid2 = -1;
}

int	pipe_fd_cleanup(t_pipex vars)
{
	int	status;

	close(vars.pipe_fds[0]);
	close(vars.pipe_fds[1]);
	waitpid(vars.pid1, NULL, 0);
	waitpid(vars.pid2, &status, 0);
	return ((status >> 8) & 0xFF);
}

void	cmd_cleanup(char ***arr, char **str)
{
	free_all(*arr);
	free(*str);
}

void	close_fds(int file_fd, int *fds)
{
	close(file_fd);
	close(fds[0]);
	close(fds[1]);
}

void	free_all(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
