/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_norme2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:06:59 by amayer            #+#    #+#             */
/*   Updated: 2019/04/04 18:25:40 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



// i have a char* as the ret...


/*

int		tet_valid(char *str)					// will need to be cleaned up...
{
	int     i;
//	int     c;
	int		a;
//	int		t[4];									// i may not necessarily need to know where they, like the conecting sides, could just add all and be like whatevs...

	i = 0;
//	c = 0;
	a = 0;
//	t[0] = 0;
//	t[1] = 0;
//	t[2] = 0;
//	t[3] = 0;
	while (str[i])
	{
		if (!(str[i] == '#' || str[i] == '.' || (i % 5 == 0 && str[i] != '\n')))	// logic is a bit convoluted but should work		// removed c > 3 condition...
			return (0);
		if (str[i] == '#')
		{
			if (i % 4 != 0 && str[i + 1] == '#')			// fix in the event of piece 4 below piece 1....
			{
//				t[c]++;
//				t[c + 1]++;
				a += 2;
			}
			if (i < 15  && str[i + 4] == '#')					// 15 right ??? cuz excluding the last line...
			{
//				t[c]++;
//				t[c + t[c + 1] + 1]++;				// clever but not clever enough
				a += 2;
			}
//			if (t[c] == 0 || t[c] > 3)				// may not need after or...				// could do an if a hasn't increased... but not sure how...
//				return (0);
//			++c;
		}
		++i;
	}
	if (i != 20)			// find some way to combine with other ret? also 20 ???? or 21 ?
		return (0);
	return ((a > 5) ? 1 : 0);
//	return ((t[0] + t[1] + t[2] + t[3] > 5) ? 1 : 0);
}

*/


int		tet_valid(char *str)
{
	int     i;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && !(i % 5 == 0 && str[i] != '\n'))
			return (0);
		if (str[i] == '#')
		{
			if (i % 4 != 0 && str[i + 1] == '#')
				a += 2;
			if (i < 15  && str[i + 4] == '#')					// 15 right ??? cuz excluding the last line...
				a += 2;
		}
		++i;
	}
	if (i != 20)
		return (0);
	return ((a > 5) ? 1 : 0);
}

void	solver(t_tet **lst, t_map *map)		// pos other var...
{
	t_tet	*tmp;
	int		i;

	tmp = *lst;
	while (tmp)
	{
		i = 0;
		while (i < map->size * map->size && !place_tet(i, map, tmp))
			++i;
		if (i >= map->size * map->size)			// if can't place, returns to previous call of function and tries with the next piece, or makes bord bigger.
		{
			if (tmp->letter == 'A')
			{
				free(map->str);
				++map->size;
				create_map(map);
				solver(&tmp, map);			// can just use tmp since the condition states it is the beginning :) cool...
			}
			return;
		}
		else
			solver(&(tmp->next), map);
		tmp = tmp->next;
	}
}

void	init_resolve(t_tet **lst)		// need to secure ????
{
	t_tet	*tmp;
	t_map	map;
	int		num;

	num = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->letter = 'A' + num++;
		tmp = tmp->next;
	}
	map.size = ft_sqr(num) * 2;
	create_map(&map);
	solver(lst, &map);
	print_map(&map);
	free(map.str);
}

int		read_file(int fd, t_tet **lst)	// this can be way more elegant using Tibeau's suggestions.					// a little bit long...
{
	t_tet	*new;
	int		r;
	char	buff[21];

	ft_bzero(buff, 21);
	if (!lst)
		return (0);
	while ((r = read(fd, buff, 20)) == 20)
	{
		if (!(new = (t_tet*)malloc(sizeof(t_tet))))
			return (0);
		if (!tet_valid(buff))
			return (0);
		get_coord(buff, new);														// should i secure ??? test for errors somewhere ????
		if (!(*lst))
			*lst = new;
		else
		{
			(*lst)->next = new;
			(*lst) = new;					// i think should work to keep order correct since in a while;
		}
		if ((r = read(fd, buff, 1)) == 1 && buff[0] != '\n')		// otherwise read is 0 and we at then end....
			return (0);
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
	init_resolve(&lst);
	terminate_list(&lst);		// apparently no security, leave for now at least
	free(lst);
	return (0);
}






























