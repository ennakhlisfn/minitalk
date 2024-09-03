/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:56:11 by sennakhl          #+#    #+#             */
/*   Updated: 2024/04/22 11:58:09 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	send_signal(char c, int pid)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
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
		usleep(350);
		j++;
		c = c << 1;
	}
}

void	check_server_received(int sigusr)
{
	if (sigusr == SIGUSR2)
		write(1, "the message has received by server\n", 35);
	exit(0);
}

void	send_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(100);
		kill(pid, SIGUSR1);
		i++;
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
	signal(SIGUSR2, check_server_received);
	pid = ft_atoi(argv[1]);
	if (!ft_isnum(argv[1]) || pid <= 0)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		send_signal(argv[2][i], pid);
		i++;
	}
	send_end(pid);
	pause();
	return (0);
}
