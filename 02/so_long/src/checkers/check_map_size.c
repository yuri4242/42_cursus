/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:15 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/28 10:36:29 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(t_game *game)
{
	if (game->map_w > MAX_WIDTH)
	{
		ft_putstr_fd("Error: Map width must be 120 or less.\n", 2);
		return (EXIT_FAILURE);
	}
	if (game->map_h > MAX_HEIGHT)
	{
		ft_putstr_fd("Error: Map height must be 60 or less.\n", 2);
		return (EXIT_FAILURE);
	}
	if (game->map_w < MIN_WIDTH)
	{
		ft_putstr_fd("Error: Map width must be 4 or greater.\n", 2);
		return (EXIT_FAILURE);
	}
	if (game->map_h < MIN_HEIGHT)
	{
		ft_putstr_fd("Error: Map height must be 4 or greater.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
