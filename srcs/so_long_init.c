/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:43:43 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 08:57:30 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_map(t_so_long *root, char *file)
{
	int		fd;
	char	*map_str;
	char	bf[1024 + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		destroy_root(root, file, errno);
	map_str = ft_calloc(1, 1);
	if (!map_str)
	{
		destroy_root(root, "map :Failed to allocate memory", errno);
		close(fd);
	}
	read_file(root, &map_str, bf, fd);
	close(fd);
	parse_map(root, map_str);
	free(map_str);
}

static void	initialize_game(t_so_long *root, char *file)
{
	root->game = (t_game *)malloc(sizeof(t_game));
	if (!root->game)
		destroy_root(root, "Failed to allocate game", errno);
	root->game->map = NULL;
	root->game->width = 0;
	root->game->height = 0;
	root->game->player_x = -1;
	root->game->player_y = -1;
	root->game->exit_x = -1;
	root->game->exit_y = -1;
	root->game->count_coll = 0;
	root->game->count_exit = 0;
	root->game->count_player = 0;
	root->game->move_count = 0;
	load_map(root, file);
}

t_so_long	*initialize_so_long(char *file)
{
	int			i;
	t_so_long	*root;

	i = 0;
	root = malloc(sizeof(t_so_long));
	if (!root)
		destroy_root(NULL, "failed to initiate the map <>", errno);
	root->mlx = NULL;
	root->mlx_win = NULL;
	root->mlx_img = NULL;
	root->game = NULL;
	while (i < 8)
		root->player[i++] = NULL;
	root->exit = NULL;
	root->coll = NULL;
	root->wall = NULL;
	root->ground = NULL;
	root->player_frame = 0;
	root->player_dir = 2;
	initialize_game(root, file);
	initialize_window(root);
	load_game_textures(root);
	return (root);
}
