# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 17:42:42 by erlazo            #+#    #+#              #
#    Updated: 2019/04/04 18:11:05 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc $(CFLAGS)

SRCS	=	main.c					\
			extra.c					\
			extra_more.c			\


OBJS	=	$(SRCS:%.c=%.o)






.PHONEY	= all clean fclean re


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $? $(CFLAGS)

%.o: %.c $(INCL)
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
