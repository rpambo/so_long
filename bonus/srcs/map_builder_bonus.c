/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:03:57 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 17:40:51 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	free_map_memory(t_so_long *root, char *file, int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
	root->game->map = NULL;
	free(file);
	destroy_root(root, "convert_file_to_map(): malloc()", errno);
}

static void	store_object_positions(t_so_long *root,
		char *file, int index, t_counts *counts)
{
	if (file[index] == 'P')
		store_player_position(root, file, index);
	else if (file[index] == 'E')
		store_exit_position(root, file, index);
	else if (file[index] == 'C')
		store_collectible_position(root, file, index, counts);
	else if (file[index] == 'R')
		store_enemy_position(root, file, index, counts);
}

void	convert_file_to_map(t_so_long *root, char *file)
{
	int			i;
	int			j;
	int			file_index;
	t_counts	counts;

	counts.collectibles = 0;
	counts.enemies = 0;
	file_index = 0;
	j = -1;
	while (++j < root->game->height)
	{
		root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
		if (!root->game->map[j])
			free_map_memory(root, file, root->game->map, j);
		i = 0;
		while (i < root->game->width)
		{
			while (file[file_index] == '\n')
				file_index++;
			store_object_positions(root, file, file_index, &counts);
			root->game->map[j][i++] = file[file_index++] - 48;
		}
	}
}
