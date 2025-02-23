/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:41:56 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/22 21:02:57 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int key, t_so_long *root)
{
	if (key == 65307)
		destroy_root(root, 0, 0);
	else if (key == 'w' || key == 65362)
		move_player(root, 0, -1);
	else if (key == 's' || key == 65364)
		move_player(root, 0, 1);
	else if (key == 'a' || key == 65361)
		move_player(root, -1, 0);
	else if (key == 'd' || key == 65363)
		move_player(root, 1, 0);
	return (0);
}
