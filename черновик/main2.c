/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:48:42 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/13 14:22:13 by boris            ###   ########.fr       */
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
	play.min = -100;
	play.x = 0;
	play.y = 0;
	if (init_player(&play, fd1))
	{
		if (init_info(&(play.map),fd1))
		{
			if (init_map(&play,fd1))
			{
				if (init_info(&(play.figure),fd1))
				{
					if (init_figure(&(play.figure),fd1))
					{
						hot_map(&(play.map));
						push_figure(&play);
						write(fd, &(play.en), 1);
						write(fd, " ", 1);
						write(fd, &(play.my), 1);
						write(fd, "\n", 1);
						c = ft_itoa(play.map.hmap);
						write(fd, c, ft_strlen(c));
						write(fd, " ", 1);
						c = ft_itoa(play.map.lmap);
						write(fd, c, ft_strlen(c));
						write(fd, "\n", 1);
						for (int i = 0; i < play.map.hmap; i++)
						{
							for(int j = 0; j < play.map.lmap; j++)
							{
								c = ft_itoa(play.map.map[i][j]);
								write(fd, c, ft_strlen(c));
								free(c);
							}
							write(fd, "\n", 1);
						}
						c = ft_itoa(play.figure.hmap);
						write(fd, c, ft_strlen(c));
						write(fd, " ", 1);
						c = ft_itoa(play.figure.lmap);
						write(fd, c, ft_strlen(c));
						write(fd, "\n", 1);
						for (int i = 0; i < play.figure.hmap; i++)
						{
							for(int j = 0; j < play.figure.lmap; j++)
							{
								c = ft_itoa((play.figure.map)[i][j]);
								write(fd, c, ft_strlen(c));
								free(c);
							}
							write(fd, "\n", 1);
						}
						c = ft_itoa(play.min);
						write(fd, c, ft_strlen(c));
						write(fd, " ", 1);
						c = ft_itoa(play.y);
						write(fd, c, ft_strlen(c));
						write(fd, " ", 1);
						c = ft_itoa(play.x);
						write(fd, c, ft_strlen(c));
						write(fd, "\n", 1);
					}
					else
					{
						write (fd, "blya5", 5);
					}
					
				}
				else
				{
					write (fd, "blya4", 5);
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