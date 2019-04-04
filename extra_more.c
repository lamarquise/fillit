/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:57:39 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/04 18:23:53 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_map(t_map *map)
{
	int		i;

i = 0;
	if (!(map->str = (char *)malloc(sizeof(char) * (map->size * map->size + 1))))     // +1 ???
		return (0);
	while (i++ < map->size * map->size)
		map->str[i++] = '.';
	map->str[i] = '\0';
	return (1);
}

void 	remove_tet(t_map *map, char letter)					// is this at all necessary, isn't that what backtracking is for?
{												// if the map str existed in the solver then this wouldn't be necessary at all...
	int		i;

	i = 0;
	while (i < map->size * map->size)
	{
		if (map->str[i] == letter)
			map->str[i] = '.';
		++i;
	}
}

int     check_and_place(int i, t_map *m, t_tet *e)
{
	int		b;
	int		index;

	b = 0;
	while (b < 4)
	{
		index = (e->co[b].y * m->size) + e->co[b].x;
		if (m->str[i + index] != '.')
			return (0);
		++b;
	}
	if ((i % m->size + e->w) >= m->size || (i / m->size + e->h) >= m->size)
		return (0);
	while (b < 8)
	{
		index = (e->co[b - 4].y * m->size) + e->co[b - 4].x;
		m->str[i + index] = e->letter;
		++b;
	}
	return (1);
}

int		ft_sqr(int nb)
{
	int		i;

	i = 1;
	while (i * i < nb)
		++i;
	return (i);
}

int     place_tet(int i, t_map *map, t_tet *elem)
{
	while (i < map->size * map->size)
	{
		if (check_and_place(i, map, elem))
			return (1);
		++i;
	}
	return (0);
}






