# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 18:54:52 by mah-ming          #+#    #+#              #
#    Updated: 2025/05/19 14:36:51 by mah-ming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
PRINTF_LIB = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./ft_printf

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF_LIB):
	@make -C ft_printf

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_LIB) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C ft_printf clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@make -C ft_printf fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
