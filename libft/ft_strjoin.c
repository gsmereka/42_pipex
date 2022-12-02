/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:50:23 by gsmereka          #+#    #+#             */
/*   Updated: 2022/07/13 00:12:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;
	char	*new_s;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	new_s = (char *)ft_calloc(s1_size + s2_size + 1, sizeof(char));
	while (i < (s1_size + s2_size + 1))
	{
		if (i >= s1_size)
			new_s[i] = s2[i - s1_size];
		else
			new_s[i] = s1[i];
		i++;
	}
	return ((char *)new_s);
}
