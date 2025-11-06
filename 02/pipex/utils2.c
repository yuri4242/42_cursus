/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:41:44 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/06 17:44:36 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*extract_path_fm_envp_lst(char **envp)
{
	char	*path_phrase;
	size_t	l_path;
	size_t	i;

	path_phrase = NULL;
	l_path = ft_strlen("PATH=");
	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", l_path) == 0)//PATHはマジックナンバーなので要更新
		{
			path_phrase = envp[i] + l_path;
			break ;
		}
		i++;
	}
	return (path_phrase);
}

int	check_cmd_path(char *path, char *cmd, char **cmd_fullpath)
{
	char	*path_slash;

	path_slash = ft_strjoin(path, "/");
	if (path_slash == NULL)
		return (EXIT_FAILURE);
	*cmd_fullpath = ft_strjoin(path_slash, cmd);
	if (*cmd_fullpath == NULL)
		return (EXIT_FAILURE);
	free(path_slash);
	if (access(*cmd_fullpath, X_OK) == -1)
	{
		free(*cmd_fullpath);
		*cmd_fullpath = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

char	*create_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_fullpath;
	size_t	i;

	paths = ft_split(extract_path_fm_envp_lst(envp), ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		if (check_cmd_path(paths[i], cmd, &cmd_fullpath) == EXIT_SUCCESS)
		{
			free_all(paths);
			return (cmd_fullpath);
		}
		i++;
	}
	free_all(paths);
	return (NULL);
}
