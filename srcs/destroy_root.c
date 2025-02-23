/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_root.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:40:51 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/22 21:02:14 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_game(t_game *game)
{
	int	i;

	if (game)
	{
		if (game->coll)
			free(game->coll);
		if (game->map)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
		free(game);
	}
}

static void	destroy_player(t_so_long *root, t_img **player)
{
	int	i;

	if (player)
	{
		i = 0;
		while (i < 8)
		{
			if (player[i])
				mlx_destroy_image(root->mlx, player[i]);
			i++;
		}
	}
}

void	destroy_root(t_so_long *root, char *msg, int errms)
{
	if (root)
	{
		if (root->exit)
			mlx_destroy_image(root->mlx, root->exit);
		if (root->coll)
			mlx_destroy_image(root->mlx, root->coll);
		if (root->wall)
			mlx_destroy_image(root->mlx, root->wall);
		if (root->ground)
			mlx_destroy_image(root->mlx, root->ground);
		if (root->player)
			destroy_player(root, root->player);
		if (root->mlx_img)
			mlx_destroy_image(root->mlx, root->mlx_img);
		if (root->mlx_win)
			mlx_destroy_window(root->mlx, root->mlx_win);
		if (root->mlx)
			mlx_destroy_display(root->mlx);
		if (root->game)
			destroy_game(root->game);
		free(root->mlx);
		free(root);
	}
	print_error(msg, errms);
}
