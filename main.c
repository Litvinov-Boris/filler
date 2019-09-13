/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:44:53 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/13 14:29:02 by boris            ###   ########.fr       */
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
	char *c;

	play.min = -100;
	play.x = 0;
	play.y = 0;
	if (init_player(&play, 0))
	{
		while (1)
		{
			if (init_info(&(play.map), 0))
				if (init_map(&play, 0))
					if (init_info(&(play.figure), 0))
						if (init_figure(&(play.figure), 0))
						{
							hot_map(&(play.map));
							push_figure(&play);
							c = ft_itoa(play.y);
							write(1, c, ft_strlen(c));
							write(1, " ", 1);
							c = ft_itoa(play.x);
							write(1, c, ft_strlen(c));
							write(1, "\n", 1);
						}
	}
	return(0);
}