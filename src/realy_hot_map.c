/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realy_hot_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:32:02 by boris             #+#    #+#             */
/*   Updated: 2019/09/23 21:16:22 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	hot_map(t_map *map) //проверено
{
	int i;
	int j;
	int k;

	k = 1;
	while (test_zeros(map) && k <= map->hmap * map->lmap)
	{
		i = -1;
		while (++i < map->hmap)
		{
			j = -1;
			while (++j < map->lmap)
			{
				if (map->map[i][j] == 0)
				{
					if (k == 1 && (chek_place(map, i, j, -1)))
						map->map[i][j] = k;
					else if (k != 1 && (chek_place(map, i, j, k - 1)))
						map->map[i][j] = k;
				}
			}
		}
		k++;
	}
}

int		test_zeros(t_map *map) //проверено
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->hmap)
	{
		j = -1;
		while (++j < map->lmap)
		{
			if (map->map[i][j] == 0)
				return (1);
		}
	}
	return (0);
}

int		chek_place(t_map *map, int y, int x, int k)//проверено
{
	if (y > 0 && map->map[y - 1][x] == k)
		return (1);
	if (x > 0 && map->map[y][x - 1] == k)
		return (1);
	if (y > 0 && x > 0 && map->map[y - 1][x - 1] == k)
		return (1);
	if (y < map->hmap - 1 && map->map[y + 1][x] == k)
		return (1);
	if (x < map->lmap - 1 && map->map[y][x + 1] == k)
		return (1);
	if (y < map->hmap - 1 && x < map->lmap - 1 && map->map[y + 1][x + 1] == k)
		return (1);
	if (y < map->hmap - 1 && x > 0 && map->map[y + 1][x - 1] == k)
		return (1);
	if (y > 0 && x < map->lmap - 1 && map->map[y - 1][x + 1] == k)
		return (1);
	return (0);
}

void	push_piece(t_filler *data)//проверено
{
	int i;
	int j;

	hot_map(&(data->map));
	i = -1;
	while (++i < data->map.hmap - data->piece.hmap)
	{
		j = -1;
		while (++j < data->map.lmap - data->piece.lmap)
		{
			if (chek_minus(data, i, j))
			{
				if (data->position.first = 0)
				{
					data->position.first = 1;
					fill_position(data, i, j, take_sum(data, i, j));
				}
				else if (data->position.min < take_sum(data, i, j))
					fill_position(data, i, j, take_sum(data, i, j));
			}
		}
	}
}

int		chek_minus(t_filler *data, int y, int x)//проверено
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (++i < data->piece.hmap)
	{
		j = -1;
		while (++j < data->piece.lmap)
		{
			if (data->map.map[i + y][j + x] * data->piece.map[i][j] == -2)
				k++;
		}
	}
	if (k == 1)
		return (1);
	else
		return (0);	
}