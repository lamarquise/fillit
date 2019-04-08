/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:57:39 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/08 13:25:43 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_maker(t_map *m)
{
	int		i;

	i = 0;
	if (!(m->str = (char *)malloc(sizeof(char) * (m->size * m->size + 1))))
		return (0);
	while (i < m->size * m->size)
		m->str[i++] = '.';
	m->str[i] = '\0';
	return (1);
}

int		check_and_place(int i, t_map *m, t_tet *e)
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
	if (((i % m->size + e->w) >= m->size) || ((i / m->size + e->h) >= m->size))
		return (0);
	b = 0;
	while (b < 4)
	{
		index = (e->co[b].y * m->size) + e->co[b].x;
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

void	list_end(t_tet **lst, t_tet *new_elem)
{
	t_tet	*tmp;

	if (!lst || !new_elem)
		return ;
	tmp = *lst;
	if (!(*lst))
	{
		*lst = new_elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
}

void	remove_tetri(t_map *map, char letter)
{
	int i;

	i = 0;
	while (i < map->size * map->size)
	{
		if (map->str[i] == letter)
			map->str[i] = '.';
		i++;
	}
}
