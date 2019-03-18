/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:49:19 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/18 17:19:50 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ret()								// how does exit work. is it what we want here? 
{
	write(1, "error\n", 6);
	return (0);
}


int		read_file(int fd)			// this thing reads one piece at a time and returns a val coresponding to that piece
{
	int		i;
	int		total;
	int		change;
	int		ch;
	int		start;				// could put these in a table.
	int		end;
	char	buff[2];

	ch = 0;
	start = 5;
	end = 5;
	number = 0;
	buff[1] = '\0';
	while (ch < 6)								//
	{
		i = 0;
		change = 0;
		while (ch < 5 && i < 5 && read(fd, buff, 1) > 0)		// if at any point buff not == . # or \n then error
		{
			if (!(buff[0] == '.' || buff[0] == '#' || buff[0] == '\n'))
				return(ret());
			if (i == 4 && buff[0] != '\n')
				return (ret());
			if (buff[0] == '#')					// how do i use this info on the next line to come to conclusions.
			{
				++change;
				if (start == 5)
					start = i;
				if (end == 5 || end == i - 1)
					end = i;
				else
					return (ret());
			}
			total += change; 
			++i;
		}
		if (ch == 5 && !(read(fd, buff, 1) == 0 && buff != '\n'))		// close enough, basically, if it reads it had better be \n.	will definitly need help...
			return (ret());
		++ch;
		if ( //something.... ch = 0 or -1 or whatever
	}
	

}


int		main(int ac, char **av)
{
	int		fd;
	int		read;
	char	*tab;

	if (ac != 2)								// all good.
		return (ret());
	else
	{
		read = 1;
		fd = open(av[1], O_RDONLY);

		if (!(tab = (char*)malloc(sizeof(char) * 2)));
			return (ret());

		// call a func or soenthing
		
		while (read > 0)
		{
			read = read_file();
			if (read == -1)
				return (ret());
			
		}


		close(fd);
	}
	return (0);
}
