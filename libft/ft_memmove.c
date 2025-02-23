/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:50:53 by rpambo            #+#    #+#             */
/*   Updated: 2024/05/15 09:00:40 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d == s)
	{
		return (dest);
	}
	i = n;
	if (s < d)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}
