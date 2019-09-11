/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:08:06 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/11 20:24:46 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int fil_map(t_filler *play, char *str, int y)
{
	int	i;

	i = -1;
	while (++i < (*play).lmap)
	{
		if (*(++str) == '.')
			(*play).map[y][i] = 0;
		else if (*(str) == (*play).en[0] || *(str) == (*play).en[1])
			(*play).map[y][i] = -1;
		else if (*(str) == (*play).my[0] || *(str) == (*play).my[1])
			(*play).map[y][i] = -2;
		else
			return(0);
	}
	return (1);
}