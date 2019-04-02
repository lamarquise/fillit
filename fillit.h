/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:55:06 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/02 17:48:17 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//# define BS = 5				// don't need this i believe


//# include "libft.h"			// may not need this....
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_piece			// do i wanna use a list? it stores the order, but might be a lot harder for the backtracking...
{
	int		order;				//like where its at relative to the other pieces.
	char	*str;
	int		t[4];
	int		l;					//largest number of sides... ?
	int		s;
}				t_piece;

char	*make_grid(int size);


#endif
