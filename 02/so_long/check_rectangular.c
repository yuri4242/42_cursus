/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:45:01 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 16:45:39 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_game *game)
{
	int		i;
	size_t	width;

	if (!game->map || !game->map[0])
		return (EXIT_FAILURE);
	width = ft_strlen(game->map[0]);
	game->map_w = (int)width;
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != width)
		{
			ft_putstr_fd("Error: Map is not rectangular.\n", 2);
			return (EXIT_FAILURE);
		}
		i++;
	}
	game->map_h = i;
	return (EXIT_SUCCESS);
}
