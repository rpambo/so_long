/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:16:54 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 08:57:50 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_texture(t_so_long *root, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (*img == 0)
		destroy_root(root, "error image", 0);
	(*img)->width = width;
	(*img)->height = height;
}

void	load_game_textures(t_so_long *root)
{
	load_texture(root, &root->player[0], "./textures/player_up_closed.xpm");
	load_texture(root, &root->player[1], "./textures/player_up_open.xpm");
	load_texture(root, &root->player[2], "./textures/player_down_closed.xpm");
	load_texture(root, &root->player[3], "./textures/player_down_open.xpm");
	load_texture(root, &root->player[4], "./textures/player_left_closed.xpm");
	load_texture(root, &root->player[5], "./textures/player_left_open.xpm");
	load_texture(root, &root->player[6], "./textures/player_right_closed.xpm");
	load_texture(root, &root->player[7], "./textures/player_right_open.xpm");
	load_texture(root, &root->exit, "./textures/house.xpm");
	load_texture(root, &root->coll, "./textures/pokeball.xpm");
	load_texture(root, &root->wall, "./textures/wall.xpm");
	load_texture(root, &root->ground, "./textures/sand.xpm");
}

void	initialize_window(t_so_long *root)
{
	root->mlx = mlx_init();
	if (!root->mlx)
		destroy_root(root, "Can't load mlx", 0);
	root->mlx_win = mlx_new_window(root->mlx,
			SCREENWIDTH, SCREENHEIGHT, "so_long");
	if (!root->mlx_win)
		destroy_root(root, "Window can't open", 0);
	root->mlx_img = mlx_new_image(root->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!root->mlx_img)
		destroy_root(root, "mlx_new_image", 0);
}
