/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:38:10 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 09:00:49 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_error(char *errmsg, int errnum)
{
	if (errmsg || errnum)
	{
		ft_putendl_fd("Error!", 2);
		if (errmsg)
		{
			ft_putstr_fd(errmsg, 2);
			if (errnum)
			{
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(strerror(errnum), 2);
			}
		}
		else if (errnum)
		{
			ft_putstr_fd(strerror(errnum), 2);
		}
		ft_putendl_fd("", 2);
	}
	else
		ft_putendl_fd("Exiting program.", 2);
	exit(1);
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
