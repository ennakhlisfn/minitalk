/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:50:45 by sennakhl          #+#    #+#             */
/*   Updated: 2024/04/18 13:34:01 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	handler(int sigusr);
void	print_mess_or_stop(char *mess);
void	ft_stradd(char *mess, char c);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr(int n);
int		ft_isnum(char *str);
int		ft_atoi(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
