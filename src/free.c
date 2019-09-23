/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:11:19 by boris             #+#    #+#             */
/*   Updated: 2019/09/21 13:30:32 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_map(t_map *map)//проверенно
{
	int i;

	if (map->map != NULL)
	{
		i = -1;
		while (map->map[++i] != NULL)
		{
			free(map->map[i]);
			map->map[i] = NULL;
		}
		free(map->map);
		map->map = NULL;
	}
}