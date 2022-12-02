/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:48 by gsmereka          #+#    #+#             */
/*   Updated: 2022/06/23 06:28:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calculate_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_print_n(int size, int n, int fd)
{
	int	temp_n;
	int	i;

	while (size > 0)
	{
		i = size - 1;
		temp_n = n;
		while (i > 0)
		{
			temp_n = temp_n / 10;
			i--;
		}
		temp_n = (temp_n % 10) + '0';
		ft_putchar_fd(temp_n, fd);
		size--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	size;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		size = ft_calculate_size(n);
		ft_print_n(size, n, fd);
	}
}
