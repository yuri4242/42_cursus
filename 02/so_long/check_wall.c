/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:44:09 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 16:44:39 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_w)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->map_h - 1][i] != '1')
		{
			ft_putstr_fd("Error: Map is not surrounded by wall.\n", 2);
			return (EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < game->map_h)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][game->map_w - 1] != '1')
		{
			ft_putstr_fd("Error: Map is not surrounded by wall.\n", 2);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
