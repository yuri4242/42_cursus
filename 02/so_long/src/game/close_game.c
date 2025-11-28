/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:12:48 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/28 12:06:42 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	destroy_images(t_game *game)
{
	if (game->img.wall_lu)
		mlx_destroy_image(game->mlx, game->img.wall_lu);
	if (game->img.wall_ru)
		mlx_destroy_image(game->mlx, game->img.wall_ru);
	if (game->img.wall_ll)
		mlx_destroy_image(game->mlx, game->img.wall_ll);
	if (game->img.wall_rl)
		mlx_destroy_image(game->mlx, game->img.wall_rl);
	if (game->img.wall_v)
		mlx_destroy_image(game->mlx, game->img.wall_v);
	if (game->img.wall_h)
		mlx_destroy_image(game->mlx, game->img.wall_h);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.obstacle)
		mlx_destroy_image(game->mlx, game->img.obstacle);
}

static void	destroy_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

static void	destroy_display(t_game *game)
{
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_game(t_game *game)
{
	destroy_images(game);
	destroy_window(game);
	destroy_display(game);
	free_map(game->map);
	exit(EXIT_SUCCESS);
	return (0);
}
