/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:21:10 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 16:52:01 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	render_sprite(t_so_long *root, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	j = 0;
	while (j < SQUARE_SIZE)
	{
		i = 0;
		while (i < SQUARE_SIZE)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
			{
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			}
			i++;
		}
		j++;
	}
}

static void	render_objects(t_so_long *root, int i, int j)
{
	int	k;
	int	index;

	if (root->game->exit_x == i && root->game->exit_y == j)
		render_sprite(root, root->exit, i * SQUARE_SIZE, j * SQUARE_SIZE);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			render_sprite(root, root->coll, i * SQUARE_SIZE, j * SQUARE_SIZE);
	if (root->game->player_x == i && root->game->player_y == j)
	{
		index = root->player_dir * 2 + root->player_frame;
		render_sprite(root, root->player[index], i
			* SQUARE_SIZE, j * SQUARE_SIZE);
	}
	k = -1;
	while (++k < root->game->count_enemy)
		if (root->game->enemy[k].x == i && root->game->enemy[k].y == j)
			render_sprite(root, root->enemy, i * SQUARE_SIZE, j * SQUARE_SIZE);
}

static void	render_map(t_so_long *root)
{
	int	i;
	int	j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			if (root->game->map[j][i] == 1)
			{
				render_sprite(root, root->wall,
					i * SQUARE_SIZE, j * SQUARE_SIZE);
			}
			else
			{
				render_sprite(root, root->ground, i
					* SQUARE_SIZE, j * SQUARE_SIZE);
			}
			render_objects(root, i, j);
			i++;
		}
		j++;
	}
}

void	render_frame(t_so_long *root)
{
	render_map(root);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
}
