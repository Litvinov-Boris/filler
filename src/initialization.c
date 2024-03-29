/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:24:19 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/26 20:26:12 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_map(t_map *map)
{
	map->hmap = 0;
	map->lmap = 0;
	map->map = NULL;
	map->cur_hmap = 0;
}

void	init_position(t_position *position)
{
	position->x = 0;
	position->y = 0;
	position->min = 0;
	position->first = 0;
}

void	init_data(t_filler *data)
{
	data->my[0] = 0;
	data->my[1] = 0;
	data->en[0] = 0;
	data->en[1] = 0;
	init_map(&(data->map));
	init_map(&(data->piece));
	init_position(&(data->position));
}

int		init_player(t_filler *data, char *line)
{
	if (ft_strstr(line, "$$$ exec p1 : "))
	{
		data->my[0] = 'o';
		data->my[1] = 'O';
		data->en[0] = 'x';
		data->en[1] = 'X';
	}
	else if (ft_strstr(line, "$$$ exec p2 : "))
	{
		data->my[0] = 'x';
		data->my[1] = 'X';
		data->en[0] = 'o';
		data->en[1] = 'O';
	}
	else
	{
		perror("Invalid Player");
		return (0);
	}
	return (1);
}

int		init_plateau(t_filler *data, char *line)
{
	if (data->map.hmap == 0 || data->map.lmap == 0)
	{
		data->map.hmap = ft_atoi(ft_strstr(line, " ") + 1);
		data->map.lmap = ft_atoi(ft_strstr((ft_strstr(line, " ") + 1),
							" ") + 1);
		data->map.cur_hmap = 0;
		if (!(data->map.map = (int**)ft_memalloc(sizeof(int*) *
			(data->map.hmap + 1))))
		{
			perror("Memory Allocation Error");
			return (0);
		}
		data->map.cur_hmap = -1;
		while (++(data->map.cur_hmap) < data->map.hmap)
			if (!(data->map.map[data->map.cur_hmap] =
			(int*)ft_memalloc(sizeof(int) * data->map.lmap)))
			{
				perror("Memory Allocation Error");
				return (0);
			}
	}
	data->map.cur_hmap = 0;
	if (!(read_map(data)))
		return (0);
	return (1);
}
