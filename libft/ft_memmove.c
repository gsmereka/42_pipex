/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:48:45 by gsmereka          #+#    #+#             */
/*   Updated: 2022/06/14 22:28:25 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*byte_dest;
	unsigned char	*byte_src;
	size_t			i;

	i = n;
	byte_dest = (unsigned char *)dest;
	byte_src = (unsigned char *)src;
	if (byte_src < byte_dest)
	{
		while (i > 0)
		{
			i--;
			byte_dest[i] = byte_src[i];
		}
		dest = byte_dest;
		return ((void *)dest);
	}
	ft_memcpy(byte_dest, byte_src, n);
	return ((void *)dest);
}
