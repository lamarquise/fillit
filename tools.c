/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:01:50 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/20 19:07:28 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*make_grid(int size)
{
	char	*grid;
	int		i;

	i = 0;
	if (!(grid = (char*)malloc(sizeof(char) * (size * size + 1))))
		return (0);
	grid[size * size] = '\0';
	while (i < size * size)
		grid[i++] = '.';
	return (grid);
}
