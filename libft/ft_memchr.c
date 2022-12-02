/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 06:39:04 by gsmereka          #+#    #+#             */
/*   Updated: 2022/06/09 07:09:41 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_char;

	s_char = (unsigned char *)s;
	while (n > 0)
	{
		n--;
		if (*s_char == (unsigned char)c)
			return ((void *)s_char);
		s_char++;
	}
	return (NULL);
}
