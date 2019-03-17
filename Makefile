# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 17:42:42 by erlazo            #+#    #+#              #
#    Updated: 2019/03/17 17:49:06 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

CC	=		gcc

CFLAGS =	-Wall -Werror -Wextra -I$(INCLUDE)








all: $(NAME)

$(NAME):


clean:
	rm 

fclean: clean


re:	fclean all
