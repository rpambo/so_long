/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:04:46 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/22 20:56:22 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animate_player(t_so_long *root)
{
	root->player_frame = (root->player_frame + 1) % 2;
	render_frame(root);
	return (0);
}

int	is_ber(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 4)
		return (0);
	if (ft_strncmp(argv + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_so_long	*root;

	if (argc != 2)
		print_error("Usage: ./so_long maps/*.ber", 0);
	if (!is_ber(argv[1]))
		print_error("Invalid file extension. Must be .ber", 0);
	root = initialize_so_long(argv[1]);
	if (!root)
		print_error("Failed to initialize game", errno);
	render_frame(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, handle_input, root);
	mlx_hook(root->mlx_win, 17, 0, close_window, root);
	mlx_loop(root->mlx);
	return (0);
}
