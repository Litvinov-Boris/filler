/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:35:48 by boris             #+#    #+#             */
/*   Updated: 2019/09/13 14:23:41 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    free_map(t_map *obj)
{
	int i;

	if ((*obj).map)
	{
		i = -1;
		while ((*obj).map[++i])
			free ((*obj).map[i]);
		free((*obj).map);
	}
}

int test_zero(t_map	*map)
{
	int	i;
	int	j;

	i = -1;
	while(++i < (*map).hmap)
	{
		j = -1;
		while(++j < (*map).lmap)
			if((*map).map[i][j] == 0)
				return (1);
	}
	return (0);
}

int	chek_zap(t_map *map, int y, int x, int k)
{
	if (y > 0 && (*map).map[y - 1][x] == k)
		return (1);
	if (x > 0 && (*map).map[y][x - 1] == k)
		return (1);
	if (y > 0 && x > 0 && (*map).map[y - 1][x - 1] == k)
		return (1);
	if (y < (*map).hmap - 1 && (*map).map[y + 1][x] == k)
		return (1);
	if (x < (*map).lmap - 1 && (*map).map[y][x + 1] == k)
		return (1);
	if (x < (*map).lmap - 1 && y < (*map).hmap - 1 && (*map).map[y + 1][x + 1] == k)
		return (1);
	if (y > 0 && x < (*map).lmap - 1 && (*map).map[y - 1][x + 1] == k)
		return (1);
	if (x > 0 && y < (*map).hmap - 1 && (*map).map[y + 1][x - 1] == k)
		return (1);
	return (0);
}

int	chek_minus(t_filler *obj, int y, int x)
{
	int	i;
	int j;

	i = -1;
	while(++i < (*obj).figure.hmap)
	{
		j = -1;
		while (++j < (*obj).figure.lmap)
			if ((*obj).figure.map[i][j] * (*obj).map.map[y + i][x + j] == -2)
				return (1);
	}
	return (0);
}

int	take_sum(t_filler *obj, int y, int x)
{
	int	i;
	int j;
	int	sum;

	sum = 0;
	i = -1;
	while(++i < (*obj).figure.hmap)
	{
		j = -1;
		while (++j < (*obj).figure.lmap)
			sum += (*obj).figure.map[i][j] * (*obj).map.map[y + i][x + j];
	}
	return (sum);
}