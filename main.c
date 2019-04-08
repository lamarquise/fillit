/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_norme2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:06:59 by amayer            #+#    #+#             */
/*   Updated: 2019/04/08 20:20:20 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tet_valid(char *str)
{
	int		i;
	int		a;
	int		c;

	i = 0;
	a = 0;
	c = 0;
	while (str[i])
	{
		if (((i + 1) % 5 != 0 && str[i] != '#' && str[i] != '.')
			|| ((i + 1) % 5 == 0 && str[i] != '\n'))
			return (0);
		if (str[i] == '#')
		{
			++c;
			if (str[i + 1] == '#')
				a += 2;
			if (i < 15 && str[i + 5] == '#')
				a += 2;
		}
		++i;
	}
	if (i != 20 || c != 4 || a < 6)
		return (0);
	return (1);
}

int		solver(t_tet *lst, t_map *map)
{
	int		i;

	if (!lst)
		return (1);
	i = 0;
	while (i < map->size * map->size)
	{
		if (check_and_place(i, map, lst))
		{
			if (solver(lst->next, map))
				return (1);
			remove_tetri(map, lst->letter);
		}
		++i;
	}
	if (lst->letter == 'A')
	{
		free(map->str);
		++map->size;
		if (!map_maker(map))
			return (0);
		return (solver(lst, map));
	}
	return (0);
}

int		init_resolve(t_tet *lst)
{
	t_tet	*tmp;
	t_map	map;
	int		num;

	num = 0;
	tmp = lst;
	while (tmp)
	{
		tmp->letter = 'A' + num;
		++num;
		tmp = tmp->next;
	}
	map.size = ft_sqr(num * 4);
	if (!map_maker(&map))
		return (0);
	if (!solver(lst, &map))
		return (0);
	print_map(&map);
	free(map.str);
	return (1);
}

int		read_file(int fd, t_tet **lst)
{
	t_tet	*new;
	int		p;
	int		r;
	char	buff[21];
	int		check;

	p = 0;
	check = 0;
	ft_bzero(buff, 21);
	while ((r = read(fd, buff, 20)) == 20)
	{
		++p;
		if (!(new = (t_tet *)malloc(sizeof(t_tet))))
			return (0);
		new->next = NULL;
		if (!tet_valid(buff))
			return (0);
		get_coord(buff, lst, new);
		if ((r = read(fd, buff, 1)) == 1 && buff[0] != '\n')
			return (0);
		else if (r == 0)
			check = 1;
	}
	return ((p > 26) ? 0 : check);
}

int		main(int argc, char **argv)
{
	t_tet		*lst;
	int			fd;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!read_file(fd, &lst))
	{
		write(1, "error\n", 6);
		terminate_list(&lst);
		free(lst);
		return (0);
	}
	if (!init_resolve(lst))
		return (0);
	terminate_list(&lst);
	free(lst);
	return (0);
}
