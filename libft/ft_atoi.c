/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:33 by gsmereka          #+#    #+#             */
/*   Updated: 2022/06/15 22:05:49 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	save;
	int	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	save = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-' || ft_isdigit(nptr[i]) > 0)
	{
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				sign = -1;
			i++;
		}
		while (ft_isdigit(nptr[i]) > 0)
		{
			save = (save * 10) + (nptr[i] - '0');
			i++;
		}
	}
	return (save * sign);
}
