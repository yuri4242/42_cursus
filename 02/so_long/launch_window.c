/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:20:39 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 12:12:25 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window_size(t_game *game)
{
	int	height;

	game->map_w = ft_strlen(game->map[0]);
	height = 0;
	while (game->map[height])
		height++;
	game->map_h = height;
}

void	init_game_vars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'C')
				game->collectible_count++;
			x++;
		}
		y++;
	}
}

int	set_map_info(char *filepath, t_game *game)
{
	game->map = read_map(filepath);
	init_game_vars(game);
	if (game->map == NULL)
	{
		ft_putstr_fd("Error: Failed to load map file.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	launch_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_putstr_fd("Error: Failed to init MiniLibX.\n", 2);
		return (EXIT_FAILURE);
	}
	init_window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w * 32, game->map_h * 32,
			"so_long");
	if (game->win == NULL)
	{
		ft_putstr_fd("Failed to launch window.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
