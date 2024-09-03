/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:34:51 by sennakhl          #+#    #+#             */
/*   Updated: 2024/04/18 14:01:26 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H
# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	check_server_received(int sigusr);
void	handler(int sigusr, siginfo_t *info);
void	print_mess_or_stop(char *mess, int pid);
void	ft_stradd(char *mess, char c);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr(int n);
int		ft_isnum(char *str);
int		ft_atoi(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
