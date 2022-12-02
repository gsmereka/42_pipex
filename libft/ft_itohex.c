/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:55:25 by gsmereka          #+#    #+#             */
/*   Updated: 2022/07/14 08:02:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calculate_size(unsigned long long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_itohex(unsigned long long n)
{
	char	*str;
	size_t	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_calculate_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		if (n % 16 > 9)
			str[size - 1] = (n % 16) + 'a' - 10;
		else
			str[size - 1] = (n % 16) + '0';
		n = n / 16;
		size--;
	}
	return (str);
}
