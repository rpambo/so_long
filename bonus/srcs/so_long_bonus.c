/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:04:46 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/23 16:53:43 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	animate_player(t_so_long *root)
{
	root->player_frame = (root->player_frame + 1) % 2;
	render_frame(root);
}

int	game_loop(t_so_long *root)
{
	static int	frame_count = 0;

	if (frame_count % 20 == 0)
		move_enemy(root);
	render_frame(root);
	display_move_count(root);
	frame_count++;
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
	mlx_loop_hook(root->mlx, game_loop, root);
	mlx_hook(root->mlx_win, 2, 1L << 0, handle_input, root);
	mlx_loop(root->mlx);
	return (0);
}
