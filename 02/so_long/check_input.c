/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:46:02 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 17:02:36 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(char *filepath)
{
	size_t	len;
	int		fd;

	if (filepath == NULL)
		return (EXIT_FAILURE);
	len = ft_strlen(filepath);
	if (len < ft_strlen(MAP_EXTENSION))
	{
		ft_putstr_fd("Error: The file name must be <path/name>.ber\n", 2);
		return (EXIT_FAILURE);
	}
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Not found or Permission denied.\n", 2);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
