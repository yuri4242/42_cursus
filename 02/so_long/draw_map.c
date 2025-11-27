/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:23:06 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 19:17:48 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_textures(void *mlx, t_texture *img)
{
	int	w;
	int	h;

	img->wall_lu = mlx_xpm_file_to_image(mlx, WALL_LU, &w, &h);
	img->wall_ru = mlx_xpm_file_to_image(mlx, WALL_RU, &w, &h);
	img->wall_ll = mlx_xpm_file_to_image(mlx, WALL_LL, &w, &h);
	img->wall_rl = mlx_xpm_file_to_image(mlx, WALL_RL, &w, &h);
	img->wall_v = mlx_xpm_file_to_image(mlx, WALL_V, &w, &h);
	img->wall_h = mlx_xpm_file_to_image(mlx, WALL_H, &w, &h);
	img->floor = mlx_xpm_file_to_image(mlx, FLOOR, &w, &h);
	img->collectible = mlx_xpm_file_to_image(mlx, COLLECTIBLE, &w, &h);
	img->player = mlx_xpm_file_to_image(mlx, PLAYER, &w, &h);
	img->exit = mlx_xpm_file_to_image(mlx, EXIT, &w, &h);
	img->obstacle = mlx_xpm_file_to_image(mlx, OBSTACLE, &w, &h);
	if (!img->wall_lu || !img->wall_ru || !img->wall_ll || !img->wall_rl
		|| !img->wall_v || !img->wall_h
		|| !img->floor || !img->collectible
		|| !img->player || !img->exit
		|| !img->obstacle)
	{
		ft_putstr_fd("Error: Falied to load xpm file.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx,
				game->win, game->img.floor, x * 32, y * 32);
			img = NULL;
			set_img(game, &img, x, y);
			if (img != NULL && img != game->img.floor)
				mlx_put_image_to_window(game->mlx,
					game->win, img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	map_image_output(t_game *game)
{
	if (init_textures(game->mlx, &game->img) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (draw_map(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
