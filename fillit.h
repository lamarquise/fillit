/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:49:01 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/03 19:32:12 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft/libft.h"


typedef struct	s_map
{
	int		map_size;
	int		total;
	int		last_pos;
	char	*str;
}				t_map;

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct	s_tetri
{
	t_coords	coords[4];
	char		letter;
	int			last_pos;							// this could be improved if used coor relative to 1st
	int			w;
	int			h;
}				t_tetri;


typedef struct	s_tet
{
	t_coords		first[4];						// the last 3 are relative to the first one...
	char			order;

	struct s_tet	*next;
}				t_tet;




// declarer fonctions


#endif













