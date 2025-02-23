/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:08:31 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 17:51:05 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

# define SQUARE_SIZE 40
# define SCREENWIDTH  1920
# define SCREENHEIGHT 1080

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct s_counts
{
	int	collectibles;
	int	enemies;
}	t_counts;

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_game
{
	int		**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		count_coll;
	int		count_exit;
	int		count_player;
	int		count_enemy;
	int		enemy_dir_x;
	int		enemy_dir_y;
	int		move_count;
	t_coord	*coll;
	t_coord	*enemy;
}	t_game;

typedef struct s_so_long
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
	t_img	*player[8];
	t_img	*exit;
	t_img	*coll;
	t_img	*wall;
	t_img	*ground;
	t_img	*enemy;
	t_game	*game;
	int		player_frame;
	int		player_dir;
}	t_so_long;

int				handle_input(int key, t_so_long *root);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

void			display_move_count(t_so_long *root);
void			animate_player(t_so_long *root);
void			destroy_root(t_so_long *root, char *msg, int errms);
void			print_error(char *errmsg, int errnum);
void			game_init(t_so_long *root, char *file);
void			read_file(t_so_long *root, char **file, char buf[], int fd);
void			map_calculate_width(t_so_long *root, char *file);
void			map_calculate_height(t_so_long *root, char *file);
void			parse_map(t_so_long *root, char *map_str);
void			validate_map(t_so_long *root, char *file);
void			convert_file_to_map(t_so_long *root, char *file);
void			print_map(t_game *game);
void			initialize_window(t_so_long *root);
void			load_game_textures(t_so_long *root);
void			render_frame(t_so_long *root);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
void			clear_image(t_img *img);
void			move_player(t_so_long *root, int dx, int dy);
void			move_enemy(t_so_long *root);
void			store_enemy_position(t_so_long *root,
					char *file, int index, t_counts *counts);
void			store_collectible_position(t_so_long *root,
					char *file, int index, t_counts *counts);
void			store_exit_position(t_so_long *root, char *file, int index);
void			store_player_position(t_so_long *root, char *file, int index);

t_so_long		*initialize_so_long(char *file);

#endif
