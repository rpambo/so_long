/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:14:54 by rpambo            #+#    #+#             */
/*   Updated: 2024/05/14 14:59:16 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	count;
	unsigned char	*memory;

	memory = s;
	count = 0;
	while (count < n)
	{
		memory[count] = c;
		count++;
	}
	return (memory);
}
