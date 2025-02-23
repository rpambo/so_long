/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:33:15 by rpambo            #+#    #+#             */
/*   Updated: 2025/02/22 21:10:59 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	append_to_file(t_so_long *root,
		char **file, const char *buf, int fd)
{
	char	*new_file;

	if (*file)
		new_file = ft_strjoin(*file, buf);
	else
		new_file = ft_strjoin("", buf);
	if (!new_file)
	{
		free(*file);
		close(fd);
		destroy_root(root, "map_init() ft_strjoin()", errno);
	}
	if (*file)
		free(*file);
	*file = new_file;
}

void	read_file(t_so_long *root, char **file, char buf[], int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, 1024);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		append_to_file(root, file, buf, fd);
		bytes_read = read(fd, buf, 1024);
	}
	if (bytes_read == -1)
	{
		free(*file);
		close(fd);
		destroy_root(root, "map_init() read()", errno);
	}
}
