/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:26:21 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/26 18:28:08 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_texture
{
	void	*wall_lu;
	void	*wall_ru;
	void	*wall_ll;
	void	*wall_rl;
	void	*wall_v;
	void	*wall_h;
	void	*floor;
	void	*collectible;
	void	*player;
	void	*exit;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_w;
	int			map_h;
	t_texture	img;
}	t_game;

# define WALL_LU "./textures/left_upper_fence.xpm"
# define WALL_RU "./textures/right_upper_fence.xpm"
# define WALL_LL "./textures/left_lower_fence.xpm"
# define WALL_RL "./textures/right_lower_fence.xpm"
# define WALL_V "./textures/vertical_fence.xpm"
# define WALL_H "./textures/horizontal_fence.xpm"
# define FLOOR "./textures/grass_floor.xpm"
# define COLLECTIBLE "./textures/coin.xpm"
# define PLAYER "./textures/player_front1.xpm"
# define EXIT "./textures/goal.xpm"

//start_game.c
int		start_game(char *filepath);

//read_map.c
char	**read_map(char *filepath);

//launch_window.c
void	init_window_size(t_game *game);
int		set_map_info(char *filepath, t_game *game);
int		launch_window(t_game *game);

//draw_map.c
int		map_image_output(t_game *game);

//set_img.c
void	set_img(t_game *game, void **img, int x, int y);

#endif
