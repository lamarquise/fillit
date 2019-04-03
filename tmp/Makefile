# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 11:12:32 by amayer            #+#    #+#              #
#    Updated: 2019/04/03 17:56:14 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = main_norme2.c
HEADERS = fillit.h
OBJ = $(SRC:%.c=%.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft 

libft:
	make -C libft/

%.o: %.c $(HEADERS)
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

clean2:
	rm -f $(OBJ)

fclean: clean2
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: libft all clean fclean re clean2
