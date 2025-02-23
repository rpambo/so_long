/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:03:57 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 08:43:38 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static void	store_object_positions(t_so_long *root, char *file,
		int index, int *collectible_count)
{
	if (file[index] == 'P')
	{
		root->game->player_x = index % (root->game->width + 1);
		root->game->player_y = index / (root->game->width + 1);
		file[index] = '0';
	}
	else if (file[index] == 'E')
	{
		root->game->exit_x = index % (root->game->width + 1);
		root->game->exit_y = index / (root->game->width + 1);
		file[index] = '0';
	}
	else if (file[index] == 'C')
	{
		root->game->coll[*collectible_count].x = index
			% (root->game->width + 1);
		root->game->coll[*collectible_count].y = index
			/ (root->game->width + 1);
		file[index] = '0';
		(*collectible_count)++;
	}
}

void	convert_file_to_map(t_so_long *root, char *file)
{
	int	i;
	int	j;
	int	file_index;
	int	collectible_count;

	collectible_count = 0;
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
			store_object_positions(root, file, file_index, &collectible_count);
			root->game->map[j][i++] = file[file_index++] - 48;
		}
	}
}
