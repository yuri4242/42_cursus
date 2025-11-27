/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:37:38 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 17:02:19 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_chars(t_game *game, int *p_count, int *e_count, int *c_count)
{
	char	c;
	int		x;
	int		y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			c = game->map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
			{
				ft_putstr_fd("Error: Map contains invalid characters.\n", 2);
				return ;
			}
			if (c == 'P')
				(*p_count)++;
			else if (c == 'E')
				(*e_count)++;
			else if (c == 'C')
				(*c_count)++;
		}
	}
}

int	check_chars(t_game *game)
{
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	count_chars(game, &p_count, &e_count, &c_count);
	if (p_count != 1)
	{
		ft_putstr_fd("Error: Map must have exactly one Start(P).\n", 2);
		return (EXIT_FAILURE);
	}
	if (e_count != 1)
	{
		ft_putstr_fd("Error: Map must have exactly one Exit(E).\n", 2);
		return (EXIT_FAILURE);
	}
	if (c_count < 1)
	{
		ft_putstr_fd("Error: Map must have at least one Collectible(C).\n", 2);
		return (EXIT_FAILURE);
	}
	game->collectible_count = c_count;
	return (EXIT_SUCCESS);
}
