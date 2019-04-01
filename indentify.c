/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:32:38 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/01 18:18:56 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		identify_piece(t_piece p)			// ok so im returning a letter corresponding to the piece.
{
												// what if i did a preliminary check and based on that test for diff sets of pieces...
	int		i;
	int		c;
	int		row;
	int		col;

	row = 0;
	col = 0;
	i = 0;
	while (t_piece->str[i])		// more parentheses?			// check row then col ??? i guess...
	{
		c = 0;
		if (t_piece->str[i] 		// yea ok i have no idea how to compare or even count number of # in a given row...
	}
}
