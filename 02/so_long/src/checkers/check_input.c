/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:46:02 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/28 11:35:46 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_path_format(char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath);
	if (len < ft_strlen(MAP_EXTENSION)
		|| ft_strncmp(filepath + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: The file name must be <path/name>.ber\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_file_open(int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Error: Not found or Permission denied.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_empty_map(int fd)
{
	int		bytes;
	char	c;

	bytes = read(fd, &c, 1);
	if (bytes <= 0)
	{
		ft_putstr_fd("Error: Map file is empty or invalid.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_input(char *filepath)
{
	int	fd;

	if (filepath == NULL)
		return (EXIT_FAILURE);
	if (check_path_format(filepath) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(filepath, O_RDONLY);
	if (check_file_open(fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_empty_map(fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
