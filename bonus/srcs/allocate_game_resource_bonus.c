/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_game_resource.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:50:21 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/24 16:50:46 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	allocate_game_resources(t_so_long *root, char *map_str)
{
	root->game->coll = malloc(sizeof(t_coord) * root->game->count_coll);
	if (!root->game->coll)
	{
		free(map_str);
		destroy_root(root,
			"Failed to allocate memory for collectibles!", errno);
	}
	root->game->enemy = malloc(sizeof(t_coord) * root->game->count_enemy);
	if (!root->game->enemy)
	{
		free(root->game->coll);
		free(map_str);
		destroy_root(root, "Failed to allocate memory for enemies!", errno);
	}
	root->game->map = malloc(sizeof(int *) * root->game->height);
	if (!root->game->map)
	{
		free(root->game->coll);
		free(root->game->enemy);
		free(map_str);
		destroy_root(root, "Failed to allocate memory for map!", errno);
	}
}
