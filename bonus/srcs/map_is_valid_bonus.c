/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:36:50 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/22 21:57:30 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	is_wall(t_so_long *root, int i, char *file)
{
	int	x;
	int	y;

	x = i % (root->game->width + 1);
	y = i / (root->game->width + 1);
	if (file[i] == '\n')
		return (0);
	if (y == 0 || y == root->game->height - 1)
		return (1);
	if (x == 0 || x == root->game->width - 1)
		return (1);
	return (0);
}

static void	validate_tile(t_so_long *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->count_player++;
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_coll++;
	else if (file[i] == 'R')
		root->game->count_enemy++;
	else if (file[i] == '1' || file[i] == '0' || file[i] == '\n')
		return ;
	else
	{
		free(file);
		destroy_root(root, "Map contains invalid characters!", 0);
	}
}

void	validate_entity_counts(t_so_long *root, char *file)
{
	if (root->game->count_player != 1
		|| root->game->count_exit != 1 || root->game->count_coll < 1)
	{
		free(file);
		destroy_root(root,
			"Map must have 1 player, 1 exit, and at least 1 collectible!", 0);
	}
}

void	validate_map(t_so_long *root, char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
		{
			i++;
			continue ;
		}
		if (is_wall(root, i, file) && file[i] != '1')
		{
			free(file);
			destroy_root(root, "Map must be surrounded by walls!", 0);
		}
		else
			validate_tile(root, file, i);
		i++;
	}
	validate_entity_counts(root, file);
}
