/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:49:01 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/06 18:51:08 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_map
{
	int		size;
	char	*str;
}				t_map;

typedef struct	s_coords
{
	int		x;
	int		y;
}				t_coords;

typedef struct	s_tet
{
	t_coords		co[4];
	char			letter;
	int				w;
	int				h;
	struct s_tet	*next;
}				t_tet;

void			terminate_list(t_tet **lst);
void			ft_bzero(void *s, size_t n);
void			print_map(t_map *map);
void			shift_tet(int min_x, int min_y, t_tet *elem);
void			get_coord(char *str, t_tet *elem);
int				map_maker(t_map *map);
void			remove_tet(t_map *map, char letter);
int				check_and_place(int i, t_map *m, t_tet *e);
int				ft_sqr(int nb);
int				place_tet(int i, t_map *map, t_tet *elem);
void			list_end(t_tet **lst, t_tet *new_elem);
void			remove_tetri(t_map *map, char letter);

#endif













