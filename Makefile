# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 14:37:29 by sennakhl          #+#    #+#              #
#    Updated: 2024/04/18 14:00:44 by sennakhl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = ft_strlen.c ft_bzero.c ft_putnbr.c server.c
CLIENT = ft_atoi.c ft_isnum.c client.c

NAME = server
NAME_B = server_bonus
SERVER_B = ft_strlen.c ft_bzero.c ft_putnbr.c server_bonus.c
CLIENT_B = ft_atoi.c ft_isnum.c client_bonus.c

OBJECTS = $(SERVER:%.c=%.o) $(CLIENT:%.c=%.o) 
OBJECTS_B = $(SERVER_B:%.c=%.o) $(CLIENT_B:%.c=%.o) 

CC = cc
CFLAGS = -Wall -Wextra -Werror
              
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(SERVER)
	$(CC) $(CFLAGS) -o client $(CLIENT)

bonus: $(NAME_B)

$(NAME_B): $(OBJECTS_B)
	$(CC) $(CFLAGS) -o server_bonus $(SERVER_B)
	$(CC) $(CFLAGS) -o client_bonus $(CLIENT_B)

clean:
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean: clean
	rm -f $(NAME) client client_bonus server_bonus

re: fclean all bonus

#.PHONY: all bonus clean fclean re
