/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:44:53 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/13 23:16:35 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int initialization(t_filler *play, int fd1)
{
	if (!init_info(&(play->map), fd1))
	{
		free_map(&(play->map));
		return (0);
	}
	if (!init_map(play, fd1))
	{
		free_map(&(play->map));
		return (0);
	}
	if (!init_info(&(play->figure), fd1))
	{
		free_map(&(play->map));
		free_map(&(play->figure));
		return (0);
	}
	if (!init_figure(&(play->figure), fd1))
	{
		free_map(&(play->map));
		free_map(&(play->figure));
		return (0);
	}
	return (1);
}

int	main()
{
	t_filler play;
	char *c;
	char *str;

	play.min = -100;
	play.x = 0;
	play.y = 0;
	int fd = open("./rez", O_RDWR);
	int fd1 = open("./test", O_RDWR);
	if (init_player(&play, fd1))
	{
		while (1)
		{
			if (initialization(&play, fd1))
			{
				hot_map(&(play.map));
				push_figure(&play);
				c = ft_itoa(play.y);
				write(fd, c, ft_strlen(c));
				write(fd, " ", 1);
				c = ft_itoa(play.x);
				write(fd, c, ft_strlen(c));
				write(fd, "\n", 1);
				free_map(&(play.map));
				free_map(&(play.figure));
				if (get_next_line(fd1, &str) == 1)
					free(str);
				play.x = 0;
				play.y = 0;
				play.min = -100;
			}
			else
				return (1);			
		}
	}
	else
		return (1);
	return (0);
}