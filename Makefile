# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 17:42:42 by erlazo            #+#    #+#              #
#    Updated: 2019/04/08 20:19:05 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc $(CFLAGS)

SRCS	=	main.c					\
			extra.c					\
			extra_more.c			\

OBJS	=	$(SRCS:%.c=%.o)

.PHONY	= all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $? $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
