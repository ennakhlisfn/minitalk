/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:54:34 by sennakhl          #+#    #+#             */
/*   Updated: 2024/04/22 11:49:38 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	send_signal(char c, int pid)
{
	int	j;
	int	i;

	j = 0;
	while (j < 8)
	{
		if (c & 128)
			i = kill(pid, SIGUSR2);
		else
			i = kill(pid, SIGUSR1);
		if (i == -1)
		{
			write(1, "PID Not Valid", 13);
			exit(1);
		}
		usleep(450);
		j++;
		c = c << 1;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		write(1, "number of arguments is not true", 31);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!ft_isnum(argv[1]) || pid <= 0)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		send_signal(argv[2][i], pid);
		i++;
	}
	return (0);
}
