/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:57:39 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/05 16:21:26 by erlazo           ###   ########.fr       */
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

int		check_and_place(int i, t_map *m, t_tet *e)				// this is my prolem aria...
{
	int		b;
	int		index;


//	printf("check test 1\n");

	b = 0;
	while (b < 4)
	{

//		printf("check test 1/2\n");

		index = (e->co[b].y * m->size) + e->co[b].x;
		if (m->str[i + index] != '.')
			return (0);
		++b;
	}
//	printf("w: %i h: %i\n", e->w, e->h);
//	if ((((i % m->size) + e->w) >= m->size) || (((i / m->size) + e->h) >= m->size))				// doesn't work....
//		return (0);
//	printf("check test 1/3\n");
	while (b < 8)
	{
		index = (e->co[b - 4].y * m->size) + e->co[b - 4].x;
		m->str[i + index] = e->letter;
		++b;
	}
//	printf("check test 2\n");
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
/*
int		place_tet(int i, t_map *map, t_tet *elem)
{
	while (i < map->size * map->size)
	{
		if (check_and_place(i, map, elem))
			return (1);
		++i;
	}
	return (0);
}
*/
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
	{
		tmp = tmp->next;
	}
	tmp->next = new_elem;
}


