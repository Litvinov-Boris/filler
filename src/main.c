/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:13:57 by boris             #+#    #+#             */
/*   Updated: 2019/09/23 21:13:30 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	test_print(t_map *map)
{
	int i;
	if (!map->map)
		printf("pyazda");
	map->cur_hmap = -1;
	while(map->map[++map->cur_hmap] != NULL)
	{
		i = -1;
		while (++i < map->lmap)
			printf("%i ", map->map[map->cur_hmap][i]);
		printf("\n");
	}
}

int	main(void)
{
	t_filler	data;
	char		*line;
	int			ret;

int a = open ("./test", O_RDONLY);
fd = 0;
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
			if (!init_plateau(&data, line))
				break;
		}
		else if (ft_strstr(line, "Piece"))
		{
			if (!init_piece(&data, line))
				break;
			push_piece(&data);
			test_print(&(data.piece));
			printf("%i, %i\n", data.position.y, data.position.x);
			init_position(&(data.position));
			free_map(&(data.piece));
			//init_position(&(data.position));
		}
	}
close(a);
	free_map(&(data.map));
	free_map(&(data.piece));
	return (0);
}