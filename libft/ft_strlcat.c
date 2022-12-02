/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 07:17:09 by gsmereka          #+#    #+#             */
/*   Updated: 2022/06/24 02:51:28 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	i;
	size_t	j;

	dest_size = ft_strlen(dest);
	i = dest_size;
	j = 0;
	if (dest_size < size - 1 && size > 0)
	{
		while (src[j] && dest_size + j < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	if (dest_size > size)
		dest_size = size;
	return (ft_strlen(src) + dest_size);
}
