/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:17:49 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/28 12:11:22 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(char *filepath)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	if (set_map_info(filepath, &game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (validate_map(&game) == EXIT_FAILURE)
	{
		free_map(game.map);
		return (EXIT_FAILURE);
	}
	if (launch_window(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (map_image_output(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_hook(game.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &game);
	mlx_hook(game.win, CROSS_BUTTON, CROSS_BUTTON_MASK, close_game, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
