/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:08:41 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 17:51:42 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wall(t_game *game, int x, int y)
{
	return (game->map[y][x] == '1');
}

static int	check_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectible_count == 0)
		{
			ft_putstr_fd("\nGame Clear!! \n", 2);
			close_game(game);
		}
		return (1);
	}
	return (0);
}

static void	check_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collectible_count--;
		game->map[y][x] = '0';
	}
}

static void	update_coordinate(t_game *game, int x, int y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->move_count++;
	ft_printf("\r\033[Kmoves: %d", game->move_count);
	draw_map(game);
}

void	move_player(t_game *game, int x, int y)
{
	int		next_x;
	int		next_y;
	char	next_tile;

	next_x = game->player_x + x;
	next_y = game->player_y + y;
	next_tile = game->map[next_y][next_x];
	if (is_wall(game, next_x, next_y))
		return ;
	if (check_exit(game, next_x, next_y))
		return ;
	check_collectible(game, next_x, next_y);
	update_coordinate(game, next_x, next_y);
}
