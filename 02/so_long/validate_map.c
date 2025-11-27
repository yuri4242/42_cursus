/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:51:44 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/27 17:04:29 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
{
	if (check_rectangular(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_wall(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_chars(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_path(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
