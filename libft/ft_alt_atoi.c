/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:33 by gsmereka          #+#    #+#             */
/*   Updated: 2022/07/20 18:49:00 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_alt_atoi(const char *nptr)
{
	int	sign;
	int	save;
	int	i;

	i = 0;
	sign = 1;
	while (nptr[i] && ft_isdigit(nptr[i]) == 0)
	{
		if (nptr[i] == '-')
		{
			sign = -1;
			i++;
		}
		i++;
	}
	save = 0;
	if (ft_isdigit(nptr[i]) > 0)
	{
		while (ft_isdigit(nptr[i]) > 0)
		{
			save = (save * 10) + (nptr[i] - '0');
			i++;
		}
	}
	return (save * sign);
}
