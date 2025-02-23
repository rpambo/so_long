/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:21:01 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 17:42:07 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	store_player_position(t_so_long *root, char *file, int index)
{
	root->game->player_x = index % (root->game->width + 1);
	root->game->player_y = index / (root->game->width + 1);
	file[index] = '0';
}

void	store_exit_position(t_so_long *root, char *file, int index)
{
	root->game->exit_x = index % (root->game->width + 1);
	root->game->exit_y = index / (root->game->width + 1);
	file[index] = '0';
}

void	store_collectible_position(t_so_long *root,
		char *file, int index, t_counts *counts)
{
	root->game->coll[counts->collectibles].x = index % (root->game->width + 1);
	root->game->coll[counts->collectibles].y = index / (root->game->width + 1);
	file[index] = '0';
	counts->collectibles++;
}

void	store_enemy_position(t_so_long *root,
		char *file, int index, t_counts *counts)
{
	root->game->enemy[counts->enemies].x = index % (root->game->width + 1);
	root->game->enemy[counts->enemies].y = index / (root->game->width + 1);
	file[index] = '0';
	counts->enemies++;
}
