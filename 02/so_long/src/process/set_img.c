/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:22:47 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 19:15:57 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_floor(t_game *game, void **img, int x, int y)
{
	int		w;
	int		h;

	w = game->map_w;
	h = game->map_h;
	if (x == 0 && y == 0)
		*img = game->img.wall_lu;
	else if (x == w - 1 && y == 0)
		*img = game->img.wall_ru;
	else if (x == 0 && y == h - 1)
		*img = game->img.wall_ll;
	else if (x == w - 1 && y == h - 1)
		*img = game->img.wall_rl;
	else if (y == 0 || y == h - 1)
		*img = game->img.wall_h;
	else if (x == 0 || x == w - 1)
		*img = game->img.wall_v;
	else
		*img = game->img.obstacle;
}

void	set_img(t_game *game, void **img, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '0')
		*img = game->img.floor;
	else if (tile == 'C')
		*img = game->img.collectible;
	else if (tile == 'P')
		*img = game->img.player;
	else if (tile == 'E')
		*img = game->img.exit;
	else if (tile == '1')
		set_floor(game, img, x, y);
}
