/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moviment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:06:37 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 18:24:20 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	display_move_count(t_so_long *root)
{
	char	*move_str;
	int		x_pos;

	move_str = ft_itoa(root->game->move_count);
	if (!move_str)
		return ;
	x_pos = SCREENWIDTH - 150;
	mlx_string_put(root->mlx, root->mlx_win, x_pos, 20, 0xFFFFFF, "Moves:");
	mlx_string_put(root->mlx,
		root->mlx_win, x_pos + 70, 20, 0xFFFFFF, move_str);
	free(move_str);
}
