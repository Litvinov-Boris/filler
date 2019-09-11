/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:44:53 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/11 11:04:58 by boris            ###   ########.fr       */
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

	int fd = open("./rez", O_RDWR);
	int fd1 = open("./test", O_RDWR);
	if (init_player(&play))
	{
		if (init_map(&play))
		{
			str = ft_itoa(play.lmap);
			write (fd, str, ft_strlen(str));
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