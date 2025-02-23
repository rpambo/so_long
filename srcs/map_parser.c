/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:32:23 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/22 21:34:00 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_map_width(t_so_long *root, char *file)
{
	int	i;

	if (!file || !file[0])
	{
		free(file);
		destroy_root(root, "Map is empty or invalid!", 0);
	}
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	root->game->width = i;
	if (root->game->width == 0)
	{
		free(file);
		destroy_root(root, "Map width is invalid!", 0);
	}
}

static void	get_map_height(t_so_long *root, char *file)
{
	int	i;
	int	width;
	int	line_width;

	width = root->game->width;
	root->game->height = 0;
	i = 0;
	while (file[i])
	{
		line_width = 0;
		while (file[i] && file[i] != '\n')
		{
			line_width++;
			i++;
		}
		if (line_width != width)
		{
			free(file);
			destroy_root(root, "Map lines are not uniform!", 0);
		}
		root->game->height++;
		if (file[i] == '\n')
			i++;
	}
}

void	parse_map(t_so_long *root, char *map_str)
{
	if (!root || !root->game || !map_str)
	{
		free(map_str);
		destroy_root(root, "Invalid arguments!", 0);
	}
	get_map_width(root, map_str);
	get_map_height(root, map_str);
	validate_map(root, map_str);
	root->game->coll = malloc(sizeof(t_coord) * root->game->count_coll);
	if (!root->game->coll)
	{
		free(map_str);
		destroy_root(root,
			"Failed to allocate memory for collectibles!", errno);
	}
	root->game->map = malloc(sizeof(int *) * root->game->height);
	if (!root->game->map)
	{
		free(root->game->coll);
		free(map_str);
		destroy_root(root, "Failed to allocate memory for map!", errno);
	}
	convert_file_to_map(root, map_str);
}
