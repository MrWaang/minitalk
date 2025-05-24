# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 05:58:09 by mah-ming          #+#    #+#              #
#    Updated: 2025/05/24 06:04:52 by mah-ming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	server
NAME_CLIENT	=	client

# Sources principales
SRCS_SERVER	=	server.c ft_printf.c ft_numbers.c ft_words.c utils.c
SRCS_CLIENT	=	client.c ft_printf.c ft_numbers.c ft_words.c utils.c

# Objects
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

# Compilation
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

# Rules
all:		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER)
			$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT)
			$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

%.o:		%.c minitalk.h ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:		clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
