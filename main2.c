/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:48:42 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/11 19:25:17 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int	main()
{
	t_filler play;
	char *str;
	char *c;

	int fd = open("./rez", O_RDWR);
	int fd1 = open("./test", O_RDWR);
	if (init_player(&play, fd1))
	{
		if (init_map_info(&play,fd1))
		{
			if (init_map(&play,fd1))
			{
				for (int i = 0; i < play.hmap; i++)
				{
					for (int j = 0; j < play.lmap; j++)
					{
						c = ft_itoa(play.map[i][j]);
						write(fd, c, ft_strlen(c));
						free(c);
					}
					write(fd, "\n", 1);
				}
			}
			else
			{
				write (fd, "blya3", 5);
			}
		}
		else
		{
			write (fd, "blya2", 5);
		}
	}
	else
	{
		write (fd, "blya1", 5);
	}
	close(fd);
	close(fd1);
	return(0);
}