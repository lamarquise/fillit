/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:09:33 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/04 18:20:09 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	terminate_list(t_tet **lst)					// yea should be fine...
{
	t_tet	*elem;
	t_tet	*tmp;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp)
		{
			elem = tmp;
			tmp = tmp->next;
			free(elem);
		}
		*lst = NULL;				// should be fine....
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	unsigned char	*str;

	a = 0;
	str = s;
	while (a < n)
	{
		str[a] = '\0';
		++a;
	}
}

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->str[i])
	{
		write(1, map->str + i, map->size);		// thank you Pascal :)
		write(1, "\n", 1);
		i += map->size;
	}
}

void    shift_tet(int min_x, int min_y, t_tet *elem)  // this puts the tets in the top left corner...
{
	int		b;
	int		max_x;
	int		max_y;

	b = 0;
	max_x = 0;
	max_y = 0;
	while (b++ < 4)
	{
		if ((elem->co[b].x -= min_x) > max_x)
			max_x = elem->co[b].x;
		if ((elem->co[b].y -= min_y) > max_y)
			max_y = elem->co[b].y;
	}
	elem->w = max_x;
	elem->h = max_y;
}

void    get_coord(char *str, t_tet *elem)                       // ok so it's actually set coord
{
	int		i;
	int		b;
	int		min_x;
	int		min_y;

	i = 0;
	b = 0;
	min_x = 5;
	min_y = 5;
	while (str[i++])
	{
		if (str[i] == '#')
		{
			if ((elem->co[b].y = i / 5) < min_y)
				min_y = elem->co[b].y;                  // or i / 5.....  but clearer like this i gess...
			if ((elem->co[b].x = i % 5) < min_x)
				min_x = elem->co[b].x;
			++b;
		}
	}
	shift_tet(min_x, min_y, elem);
}







