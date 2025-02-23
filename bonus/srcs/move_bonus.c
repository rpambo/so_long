/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:43:35 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 18:25:36 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	update_player_direction(t_so_long *root, int dx, int dy)
{
	if (dx == 1 && dy == 0)
		root->player_dir = RIGHT;
	else if (dx == -1 && dy == 0)
		root->player_dir = LEFT;
	else if (dx == 0 && dy == -1)
		root->player_dir = UP;
	else if (dx == 0 && dy == 1)
		root->player_dir = DOWN;
	animate_player(root);
}

static void	collect_item(t_so_long *root, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < root->game->count_coll)
	{
		if (root->game->coll[i].x == new_x && root->game->coll[i].y == new_y)
		{
			root->game->coll[i] = root->game->coll[root->game->count_coll - 1];
			root->game->count_coll--;
			break ;
		}
		i++;
	}
	root->game->move_count++;
}

static int	check_enemy_collision(t_so_long *root, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < root->game->count_enemy)
	{
		if (root->game->enemy[i].x == new_x && root->game->enemy[i].y == new_y)
			return (1);
		i++;
	}
	return (0);
}

void	move_player(t_so_long *root, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = root->game->player_x + dx;
	new_y = root->game->player_y + dy;
	update_player_direction(root, dx, dy);
	if (new_x < 0 || new_x >= root->game->width
		|| new_y < 0 || new_y >= root->game->height)
		return ;
	if (root->game->map[new_y][new_x] == 1)
		return ;
	if (check_enemy_collision(root, new_x, new_y))
		destroy_root(root, "Game Over! You were caught by an enemy!", 0);
	root->game->player_x = new_x;
	root->game->player_y = new_y;
	collect_item(root, new_x, new_y);
	if (root->game->count_coll == 0)
		root->game->map[root->game->exit_y][root->game->exit_x] = 2;
	if (root->game->player_x == root->game->exit_x
		&& root->game->player_y == root->game->exit_y)
	{
		if (root->game->count_coll == 0)
			destroy_root(root, 0, 0);
	}
	render_frame(root);
}
