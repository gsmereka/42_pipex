/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:46:49 by gsmereka          #+#    #+#             */
/*   Updated: 2022/06/25 02:10:15 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(const char *big, const char *litlle)
{
	while (*litlle)
	{
		if (*big != *litlle)
			return (1);
		litlle++;
		big++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	c;

	i = 0;
	c = 0;
	if (!big || !little)
		return (NULL);
	if (!little || !little[0])
		return ((char *)big);
	while (big[i] && (c < len))
	{
		if (c + ft_strlen(little) > len)
			return (NULL);
		else if (compare(&big[i], &little[0]) == 0)
			return ((char *)&big[i]);
		i++;
		c++;
	}
	return (NULL);
}
