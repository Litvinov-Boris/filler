/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:37 by boris             #+#    #+#             */
/*   Updated: 2019/09/11 11:03:55 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	init_player(t_filler *play)
{
	char *str;

	if (get_next_line(0, &str) != 1)
		return (0);
	if (ft_strstr(str, "p1"))
	{
		(*play).en[0] = 'o';
		(*play).en[1] = 'O';
		(*play).my[0] = 'x';
		(*play).my[1] = 'X';
	}
	else if (ft_strstr(str, "p1"))
	{
		(*play).en[0] = 'x';
		(*play).en[1] = 'X';
		(*play).my[0] = 'o';
		(*play).my[1] = 'O';
	}
	else
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);  
}

int init_map(t_filler *play)
{
	char	*str;
	char	*save;
	int		i;

	if (get_next_line(0, &str) != 1)
		return (0);
	save = str;
	while (*save != ' ')
		save++;
	save++;
	(*play).hmap = ft_atoi(save++);
	while (*save != ' ')
		save++;
	save++;
	(*play).lmap = ft_atoi(save++);
	free(str);
	if (((*play).map = (int**)malloc(sizeof(int) * (*play).hmap)) == NULL)
		return (0);
	i = -1;
	while (++i < (*play).hmap)
		if (((*play).map[i] = (int*)malloc(sizeof(int) * (*play).lmap)) == NULL)
		{
			free_map((play));
			return (0);
		}
	return (1);
}