/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_norme2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:06:59 by amayer            #+#    #+#             */
/*   Updated: 2019/04/05 16:21:24 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tet_valid(char *str)
{
	int     i;
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
			if (i < 15  && str[i + 5] == '#')					// 15 right ??? cuz excluding the last line...
				a += 2;
		}
		++i;
	}
	if (i != 20 || c != 4)
		return (0);
	return ((a > 5) ? 1 : 0);
}

int		solver(t_tet *lst, t_map *map)
{
	int		i;

//	printf("solver test 1\n");

//	print_map(map);


	if (!lst)
	{
//		printf("solver end\n");
		return (1);
	}
//	if (!*lst && like theres a map or something...)

	while (lst)
	{
	
		i = 0;
		while (i < map->size * map->size)
		{
//			printf("solver test 1\n");
			if (check_and_place(i, map, lst))
			{
//				printf("solver test 2\n");
				return (solver(lst->next, map));
			}
			++i;
		}

//		printf("solver test 2\n");

		if (i >= map->size * map->size)			// if can't place, returns to previous call of function and tries with the next piece, or makes bord bigger.
		{
//			printf("solver inner test 1\n");

			if (lst->letter == 'A')
			{
//				printf("solver inner test 2\n");

				free(map->str);
				++map->size;
				if (!map_maker(map))
					return (0);
				return (solver(lst, map));			// can just use tmp since the condition states it is the beginning :) cool...
			}
			return (0);
		}
		lst = lst->next;
	}
	return (0);
}

int		init_resolve(t_tet *lst)		// need to secure ????
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
	map.size = ft_sqr(num) * 2;
	
//	printf("map size = %i\n", map.size);

	if (!map_maker(&map))
		return (0);

//	printf("map: %s\n", map.str);

	print_map(&map);

//	printf("init test 1\n");

//	if (!solver(lst, &map))
//		return (0);
	solver(lst, &map);
	print_map(&map);
	free(map.str);
	return (1);
}

int		read_file(int fd, t_tet **lst)	// this can be way more elegant using Tibeau's suggestions.					// a little bit long...
{
	t_tet	*new;
	t_tet	*tmp;
	int		r;
	char	buff[21];

	ft_bzero(buff, 21);
	if (!lst)
		return (0);
	while ((r = read(fd, buff, 20)) == 20)
	{
		tmp = *lst;
		if (!(new = (t_tet*)malloc(sizeof(t_tet))))
			return (0);
		new->next = NULL;
		if (!tet_valid(buff))
			return (0);
		
//		printf("read test 1\n");
		
		get_coord(buff, new);														// should i secure ??? test for errors somewhere ????
		list_end(lst, new);
		if ((r = read(fd, buff, 1)) == 1 && buff[0] != '\n')		// otherwise read is 0 and we at then end....
			return (0);
//		printf("read test 2\n");
	}
	return (1);
}

int		main(int argc, char **argv)						// also making a linked list...
{
	t_tet		*lst;			// malloc at some point?
	int		fd;;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 27);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);						//secure ??? seems fine???
	if (!read_file(fd, &lst))
	{
		write(1, "error\n", 7);
		terminate_list(&lst);
		free(lst);						// and also free whole list, so i need a terminte list func....
		return (0);
	}

//	printf("main test 1\n");

	if (!init_resolve(lst))
		return (0);				// some error message...

//	printf("main test 2\n");

	terminate_list(&lst);		// apparently no security, leave for now at least
	free(lst);
	return (0);
}



