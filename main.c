/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:44:53 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/10 11:18:18 by boris            ###   ########.fr       */
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

	int fd = open("./rez", O_RDWR);
	if (init_player(play))
	{
		write (fd, "u", 1);
	}
	else
	{
		write (fd, "blya", 4);
	}
	close(fd);
	return(0);
}