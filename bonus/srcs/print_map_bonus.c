/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:30:36 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 08:47:52 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	printf("Height: %d\n", game->height);
	printf("Width: %d\n", game->width);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			printf("%d", game->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
