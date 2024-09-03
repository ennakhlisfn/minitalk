/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:42:31 by sennakhl          #+#    #+#             */
/*   Updated: 2023/12/02 15:08:13 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	val;

	n = 1;
	i = 0;
	val = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (n * val);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("%d\n",ft_atoi("9223372036854775807"));
	printf("%d\n",atoi("9223372036854775807"));
}*/
