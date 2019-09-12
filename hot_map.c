/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:08:06 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/12 22:37:57 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int fil_map(t_filler *play, char *str, int y)
{
	int	i;

	i = -1;
	while (++i < (*play).map.lmap)
	{
		if (*(++str) == '.')
			(*play).map.map[y][i] = 0;
		else if (*(str) == (*play).en[0] || *(str) == (*play).en[1])
			(*play).map.map[y][i] = -1;
		else if (*(str) == (*play).my[0] || *(str) == (*play).my[1])
			(*play).map.map[y][i] = -2;
		else
			return(0);
	}
	return (1);
}

int	fil_fig(t_map *play, char *str, int y)
{
	int	i;

	i = -1;
	while (++i < (*play).lmap)
	{
		if (*str == '.')
			(*play).map[y][i] = 0;
		else if (*str == '*')
			(*play).map[y][i] = 1;
		else
			return (0);
		str++;
	}
	return (1);
}

void	hot_map(t_map *map)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	while(test_zero(map))
	{
		i = -1;
		while(++i < (*map).hmap)
		{
			j = -1;
			while(++j < (*map).lmap)
				if((*map).map[i][j] == 0)
				{
					if(k == 1)
					{
						if(chek_zap(map, i, j, -1))
							(*map).map[i][j] = k;
					}
					else if(chek_zap(map, i, j, k - 1))
							(*map).map[i][j] = k;
				}
		}
		k++;
	}
}