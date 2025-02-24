/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:43:35 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/24 16:05:50 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}

void	count_player(int n)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		count_player(214748364);
		write(1, "8", 1);
	}
	else if (n > 9)
	{
		count_player(n / 10);
		a = (n % 10 + '0');
		write(1, &a, 1);
	}
	else if (n >= 0 && n <= 9)
	{
		a = (n + '0');
		write(1, &a, 1);
	}
	else
	{
		write(1, "-", 1);
		count_player(n * -1);
	}
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
	root->game->player_x = new_x;
	root->game->player_y = new_y;
	root->game->move_count++;
	printable(root->game->move_count);
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
