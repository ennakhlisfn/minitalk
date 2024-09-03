/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:35:18 by sennakhl          #+#    #+#             */
/*   Updated: 2023/11/25 08:31:05 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char	str1[]={1,2,3,4,5,6,7};
	int	str2[]={1,2,3,4,5,6,7};
	int	i = 0;
	ft_bzero(str2,16);
	bzero(str1,16);
	while (i < 7)
		printf("%d\t",str1[i++]);
	printf("\n\n");
	i = 0;
	while (i < 7)
		printf("%d\t",str2[i++]);
}*/
