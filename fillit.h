/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:49:01 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/04 18:21:07 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft/libft.h"


typedef struct	s_map
{
	int		size;
	char	*str;
}				t_map;

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct	s_tet
{
	t_coords		co[4];						// the last 3 are relative to the first one...
	char			letter;
	int				w;
	int				h;

	struct s_tet	*next;
}				t_tet;



void	terminate_list(t_tet **lst);
void	ft_bzero(void *s, size_t n);
void	print_map(t_map *map);
void	shift_tet(int min_x, int min_y, t_tet *elem);
void	get_coord(char *str, t_tet *elem);
int		create_map(t_map *map);
void	remove_tet(t_map *map, char letter);
int		check_and_place(int i, t_map *m, t_tet *e);
int		ft_sqr(int nb);
int		place_tet(int i, t_map *map, t_tet *elem);



#endif













