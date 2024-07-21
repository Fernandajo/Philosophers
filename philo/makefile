# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 18:19:30 by fjoestin          #+#    #+#              #
#    Updated: 2024/07/21 18:20:32 by fjoestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo

CC      =   cc

CFLAGS  =   -Wall -Werror -Wextra

SRCS    =   src/main.c \

OBJS    =   $(SRCS:%.c=out/%.o)

all:        $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

out/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

norminette:
	norminette $(SRCS) inc/philo.h

clean:
	rm -rf out

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re