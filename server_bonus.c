/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:32:36 by sennakhl          #+#    #+#             */
/*   Updated: 2024/04/18 14:03:06 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_stradd(char *mess, char c)
{
	int	i;

	i = 0;
	while (mess[i])
		i++;
	mess[i] = c;
}

void	print_mess_or_stop(char *mess, int pid)
{
	char	c;

	c = (mess[0] - 48) * 128;
	c += (mess[1] - 48) * 64;
	c += (mess[2] - 48) * 32;
	c += (mess[3] - 48) * 16;
	c += (mess[4] - 48) * 8;
	c += (mess[5] - 48) * 4;
	c += (mess[6] - 48) * 2;
	c += (mess[7] - 48) * 1;
	if (c == 0)
		kill(pid, SIGUSR2);
	write(1, &c, 1);
	ft_bzero(mess, 8);
}

void	handler(int sigusr, siginfo_t *info)
{
	static char	mess[8];

	if (sigusr == 10)
		ft_stradd(mess, '0');
	else if (sigusr == 12)
		ft_stradd(mess, '1');
	if (ft_strlen(mess) == 8)
		print_mess_or_stop(mess, info->si_pid);
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	act.sa_handler = (void (*)(int))handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	pid = (int)getpid();
	write(1, "the pid is: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}
