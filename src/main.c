/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:49:19 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/17 18:39:22 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ret()
{
	write(1, "error\n", 6);
	return (0);
}


int		read_file()								// would it actually be more efficient to have a massive read that is larger than the size of the largest possible valid file?



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
