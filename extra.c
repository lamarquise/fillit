/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:09:33 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/08 13:25:46 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	terminate_list(t_tet **lst)
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
		*lst = NULL;
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
		write(1, map->str + i, map->size);
		write(1, "\n", 1);
		i += map->size;
	}
}

void	shift_tet(int min_x, int min_y, t_tet *elem)
{
	int		b;
	int		max_x;
	int		max_y;

	b = 0;
	max_x = 0;
	max_y = 0;
	while (b < 4)
	{
		if ((elem->co[b].x -= min_x) > max_x)
			max_x = elem->co[b].x;
		if ((elem->co[b].y -= min_y) > max_y)
			max_y = elem->co[b].y;
		++b;
	}
	elem->w = max_x;
	elem->h = max_y;
}

void	get_coord(char *str, t_tet **lst, t_tet *elem)
{
	int		i;
	int		b;
	int		min_x;
	int		min_y;

	i = 0;
	b = 0;
	min_x = 5;
	min_y = 5;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((elem->co[b].y = i / 5) < min_y)
				min_y = elem->co[b].y;
			if ((elem->co[b].x = i % 5) < min_x)
				min_x = elem->co[b].x;
			++b;
		}
		++i;
	}
	shift_tet(min_x, min_y, elem);
	list_end(lst, elem);
}
