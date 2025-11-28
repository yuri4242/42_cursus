/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:27:40 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 16:41:46 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	copy_map(t_game *game, char ***copy)
{
	int	i;

	*copy = ft_calloc(game->map_h + 1, sizeof(char *));
	if (*copy == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < game->map_h)
	{
		(*copy)[i] = ft_strdup(game->map[i]);
		if (!(*copy)[i])
		{
			free_map(*copy);
			return (EXIT_FAILURE);
		}
		i++;
	}
	(*copy)[i] = NULL;
	return (EXIT_SUCCESS);
}

int	check_path(t_game *game)
{
	char	**tmp_map;
	int		y;
	int		x;

	if (copy_map(game, &tmp_map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	flood_fill(tmp_map, game->player_x, game->player_y);
	y = 0;
	while (tmp_map[y])
	{
		x = 0;
		while (tmp_map[y][x])
		{
			if (tmp_map[y][x] == 'C' || tmp_map[y][x] == 'E')
			{
				free_map(tmp_map);
				ft_putstr_fd("Error: Map path is invalid (Unreachable).\n", 2);
				return (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	free_map(tmp_map);
	return (EXIT_SUCCESS);
}
