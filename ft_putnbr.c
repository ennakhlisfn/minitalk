/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:31:46 by sennakhl          #+#    #+#             */
/*   Updated: 2024/03/22 15:21:50 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	long	nbr;
	long	x;
	char	c;

	nbr = n;
	x = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr / x >= 10)
		x *= 10;
	while (x > 0)
	{
		c = nbr / x + '0';
		write(1, &c, 1);
		nbr %= x;
		x /= 10;
	}
}
