/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_norme2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:06:59 by amayer            #+#    #+#             */
/*   Updated: 2019/04/03 19:32:07 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



// i have a char* as the ret...


int		check_valid_tetriminos(char *str)					// will need to be cleaned up...
{
	int     i;
	int     c;
	int		t[4];

	i = 0;
	c = 0;
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	while (str[i])
	{
		if (c > 3 || !(str[i] == '#' || str[i] == '.' || (i % 5 == 0 && str[i] != '\n')))			// logic is a bit convoluted but should work
			return (0);
		if (str[i] == '#')
		{
			

			if (i % 4 != 0 && str[i + 1] == '#')
			{
				t[c]++;
				t[c + 1]++;
			}
			if (i < 12 && p->str[i + 4] == '#')
			{
				t[c]++;
				t[c + t[c + 1] + 1]++;
			}
			if (t[c] == 0 || t[c] > 3)				// may not need after or...
				return (0);
			++c;
		}
		++i;
	}
	return ((t[0] + t[1] + t[2] + t[3] > 5) ? 1 : 0);
}


/*

   int		free_and_return(void *ptr, int r)							// wtf does this do ??????
   {
   free(ptr);
   return (r);
   }

   int		check_valid_tetriminos(char *str)
   {
   int	block;
   int	valid;
   int	count;

   block = -1;
   valid = 0;
   count = 0;
   while (++block < 19)
   {
   if (str[block] == '#')
   {
   count++;
   if (str[block - 1] || str[block + 1]
   || str[block - 5] || str[block + 5] == '#')
   valid = 1;
   }
   }
   if ((str[20] != '\n' && str[20] != '\0')
   || ft_strlen(str) < 20 || valid == 0 || count != 4)
   return (free_and_return(str, 0));							// dumb use a ternaire
   return (1);
   }

*/

int		ft_square_sup(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i += 1;
	return (i);
}

void	print_map(t_map *map, int map_size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < map_size * map_size)
	{
		ft_putchar(map->str[i]);
		i++;
		count++;
		if (count >= map_size)
		{
			count = 0;											// moron...
			ft_putchar('\n');
		}
	}
}

void	create_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	(*map).str = malloc(sizeof(char) * map_size * map_size);
	while (i < map_size * map_size)
	{
		(*map).str[i] = '.';
		i++;
	}
}

void	remove_tetri(t_map *map, int map_size, char letter)
{
	int i;

	i = 0;
	while (i < map_size * map_size)
	{
		if ((*map).str[i] == letter)
			(*map).str[i] = '.';
		i++;
	}
}

void	place_tetri_topos(int i, t_map *map, int map_size, t_tetri *tetri)
{
	int block;
	int index;

	block = 0;
	while (block < 4)
	{
		index = (tetri->coords[block].y * map_size) + tetri->coords[block].x;
		(*map).str[i + index] = tetri->letter;
		block++;
	}
}

int		check_place(int i, t_map *map, int map_size, t_tetri *tetri)				// int map size...
{
	int block;
	int index;
	int x;								// don't need these...
	int y;

	block = 0;
	while (block < 4)
	{
		index = (tetri->coords[block].y * map_size) + tetri->coords[block].x;				// if used coordonates relative to first # i think much easier...
		if ((*map).str[i + index] != '.')
			return (-1);
		block++;
	}
	x = i % map_size;
	y = i / map_size;
	if ((x + tetri->w) >= map_size)
		return (-1);
	if ((y + tetri->h) >= map_size)
		return (-1);
	return (0);
}

int		place_tetri(int i, t_map *map, int map_size, t_tetri *tetri)
{
	while (i < map_size * map_size)
	{
		if (check_place(i, map, map_size, tetri) == 0)
		{
			place_tetri_topos(i, map, map_size, tetri);
			tetri->last_pos = i;
			return (0);
		}
		i++;
	}
	return (-1);
}

void	resolve(t_tetri *tetris, t_map *map, int back, int i)
{
	while (i < map->total)
	{
		// ft_putendl(map->str);
		//print_map(map, map->map_size);
		//ft_putchar('\n');
		if (place_tetri(map->last_pos, map, map->map_size, &tetris[i]) == -1)
		{
			if (i == 0)
			{
				free(map->str);
				create_map(map, ++(map->map_size));
				map->last_pos = 0;
				back = 0;
				i = 0;
			}
			else
			{
				remove_tetri(map, map->map_size, tetris[--i].letter);
				map->last_pos = tetris[i].last_pos + 1;
			}
		}
		else
		{
			map->last_pos = 0;
			i++;
		}
	}
}

void	init_resolve(t_tetri *tetris)								// this is 1st part of resolve, def make better...
{
	int		i;
	int		map_size;
	t_map	map;
	int		total;
	int		back;

	total = 0;
	while (tetris[total].letter)
		total++;
	map.total = total;
	map.last_pos = 0;
	map_size = ft_square_sup(total * 4);
	create_map(&map, map_size);
	map.map_size = map_size;
	i = 0;
	back = 0;
	resolve(tetris, &map, back, i);
	print_map(&map, map.map_size);
	free(map.str);
}

void	shift_tetri(int min_x, int min_y, t_tetri *tetri)	// this is the second half of get_coord, im leaving both for now cuz not sure how to make better.
{
	int	block;
	int	max_x;
	int	max_y;

	max_x = 0;
	max_y = 0;
	block = 0;
	while (block < 4)
	{
		(*tetri).coords[block].x -= min_x;
		(*tetri).coords[block].y -= min_y;
		if ((*tetri).coords[block].x > max_x)
			max_x = (*tetri).coords[block].x;
		if ((*tetri).coords[block].y > max_y)
			max_y = (*tetri).coords[block].y;
		block++;
	}
	tetri->w = max_x;
	tetri->h = max_y;
}

void	get_coord(char *str, t_tetri *tetri)						// ok so it's actually set coord
{
	int	i;
	int block;
	int min_x;
	int min_y;

	i = 0;
	block = 0;
	min_x = 5;
	min_y = 5;
	while (str[i++])
	{
		if (str[i] == '#')
		{
			(*tetri).coords[block].y = i / 5;
			(*tetri).coords[block].x = i % 5;
			if ((*tetri).coords[block].y < min_y)
				min_y = (*tetri).coords[block].y;
			if ((*tetri).coords[block].x < min_x)
				min_x = (*tetri).coords[block].x;
			block++;
		}
	}
	shift_tetri(min_x, min_y, tetri);
}

int		readnload_tetris(int fd, t_tet **lst)								// this can be way more elegant using Tibeau's suggestions.
{
	t_tet	*new;
	int		i;
	int		ret;
	char	buff[21];

	buff[21] = '\0'; 					// more elegant?
	i = 0;
	if (!lst)
		return (-1);
	while ((ret = read(fd, buff, 20)) == 20)
	{
		if (!(new = (t_tet*)malloc(sizeof(t_tet))))
			return (-1);
		if (check_valid_tetriminos(buff) == 0)
			return (-1);
//		get_coord(str_tetri, &(*tetris)[i]);
		(*tetris)[i].letter = 65 + i;								// kinda redundant... 
		i++;

		if (!(*lst))
			*lst = new;
		else
		{
			(*lst)->next = new;
			(*lst) = new;					// i think should work to keep order correct since in a while;
		}
		if ((ret = read(fd, buff, 1)) == 1 && buff[0] != '\n')
			return (-1);
	}
/*
	if (ret != 20 && ret != 0)
		return (-1);
	if (ret == -1 || str_tetri[0] == '\0')
	{
		free(str_tetri);										// necessary to free ??? condition necessary at all ???
		return (-1);
	}
	free(str_tetri);
*/	return (1);
}

int		main(int argc, char **argv)						// also making a linked list...
{
	t_tet		**lst;			// may not need a new here...
	
	int		fd;
	t_tetri	*tetris;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 27);
		return (0);
	}
//	lst = (t_tet*)malloc(sizeof(t_tet) * 27);					// gross, use linked lists i think...
	fd = open(argv[1], O_RDONLY);						//secure ???
	if (readnload_tetris(fd, &tetris) != 1)
	{
		write(1, "error\n", 7);
		free(lst);						// and also free whole list, so i need a terminte list func....
		return (0);
	}
	init_resolve(tetris);
	free(tetris);
	return (0);
}
