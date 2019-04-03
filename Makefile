# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 17:42:42 by erlazo            #+#    #+#              #
#    Updated: 2019/04/03 19:32:24 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc $(CFLAGS)

SRCS	=	main.c					\
			extra.c					\
			libft/ft_strlen.c		\
			libft/ft_putchar.c		\
			libft/ft_memalloc.c		\
			libft/ft_strnew.c		\


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
