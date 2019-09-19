/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:13:57 by boris             #+#    #+#             */
/*   Updated: 2019/09/19 23:09:04 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	t_filler	data;
	char		*line;
	int			ret;

	int fd;
	fd = open ("./test", O_RDONLY);
	init_data(&data);
	while((ret = get_next_line(fd, &line)))
	{
		if(ret == -1)
		{
			perror("VM Output Read Error");
			break;
		}
		if (ft_strstr(line, "$$$"))
		{
			if (!init_player(&data, line))
				break;
		}
		else if (ft_strstr(line, "Plateau"))
		{
		}
		else if (ft_strstr(line, "Piece"))
		{
		}
	}
	close (fd);
	//чиска остатков
	return (0);
}