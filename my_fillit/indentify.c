/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:32:38 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/03 19:32:15 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		piece_sides(t_piece p)			// ok so im returning a letter corresponding to the piece.
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (p->str[i])
	{
		if (c > 3)										// could put this in last if to save space but would slow down and maybe cause problems in table...
			return (0);
		if (p->str[i] == '#')
		{
			if (i % 4 != 0 && p->str[i + 1] == '#')
			{
				p->t[c]++;
				p->t[c + 1]++;
			}
			if (i < 12 && p->str[i + 4] == '#')
			{
				p->t[c]++;
				p->t[c + p->t[c + 1] + 1]++;	// basocally, if tab[c + 1] has been added to (presumably in the prev condition, then you move on to tab[c + 2]
			}
			if (p->t[c] == 0 || p->t[c] > 3)		//second part might be redundant so slow things down...
				return (0);
			++c;
		}
		++i;
	}
	return ((p->s = p->t[0] + p->t[1] + p->t[2] + p->t[3]));
}


char		identify_piece(t_piece p)			// ok so im returning a letter corresponding to the piece.
{
												// what if i did a preliminary check and based on that test for diff sets of pieces...
	int		i;
	int		c;
	int		row;
	int		col;

	row = 0;
	col = 
}
