/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:27:06 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 16:38:26 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	get_random_direction(t_so_long *root, int i)
{
	int	possible_dirs[4];
	int	num_possible_dirs;
	int	x;
	int	y;

	num_possible_dirs = 0;
	x = root->game->enemy[i].x;
	y = root->game->enemy[i].y;
	if (y > 0 && root->game->map[y - 1][x] != 1)
		possible_dirs[num_possible_dirs++] = 0;
	if (y < root->game->height - 1
		&& root->game->map[y + 1][x] != 1)
		possible_dirs[num_possible_dirs++] = 1;
	if (x > 0 && root->game->map[y][x - 1] != 1)
		possible_dirs[num_possible_dirs++] = 2;
	if (x < root->game->width - 1
		&& root->game->map[y][x + 1] != 1)
		possible_dirs[num_possible_dirs++] = 3;
	if (num_possible_dirs > 0)
		return (possible_dirs[rand() % num_possible_dirs]);
	return (-1);
}

static void	update_enemy_position(t_so_long *root, int i, int *enemy_dirs)
{
	int	new_x;
	int	new_y;

	new_x = root->game->enemy[i].x;
	new_y = root->game->enemy[i].y;
	if (enemy_dirs[i] == 0)
		new_y--;
	else if (enemy_dirs[i] == 1)
		new_y++;
	else if (enemy_dirs[i] == 2)
		new_x--;
	else if (enemy_dirs[i] == 3)
		new_x++;
	if (new_x >= 0 && new_x < root->game->width
		&& new_y >= 0 && new_y < root->game->height
		&& root->game->map[new_y][new_x] != 1)
	{
		root->game->enemy[i].x = new_x;
		root->game->enemy[i].y = new_y;
	}
	else
		enemy_dirs[i] = -1;
}

static void	check_enemy_collision(t_so_long *root, int i)
{
	if (root->game->enemy[i].x == root->game->player_x
		&& root->game->enemy[i].y == root->game->player_y)
	{
		destroy_root(root, "Game Over", 0);
	}
}

void	move_enemy(t_so_long *root)
{
	int			i;
	static int	enemy_move_counter = 0;
	static int	enemy_dirs[100];

	if (root->game->count_enemy == 0)
		return ;
	if (++enemy_move_counter < 2)
		return ;
	enemy_move_counter = 0;
	i = 0;
	while (i < root->game->count_enemy)
	{
		if (enemy_dirs[i] == -1)
			enemy_dirs[i] = get_random_direction(root, i);
		if (enemy_dirs[i] != -1)
			update_enemy_position(root, i, enemy_dirs);
		check_enemy_collision(root, i);
		i++;
	}
}
