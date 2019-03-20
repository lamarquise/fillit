# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 17:42:42 by erlazo            #+#    #+#              #
#    Updated: 2019/03/20 18:42:43 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

INCL	=	-I includes/

CFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDE)
CC		=	gcc $(CFLAGS) $(INCL)

SRCS	=	main.c

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
