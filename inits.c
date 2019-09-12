/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:37 by boris             #+#    #+#             */
/*   Updated: 2019/09/12 21:14:13 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	init_player(t_filler *play, int fd)
{
	char *str;

	if (get_next_line(fd, &str) != 1)//
		return (0);
	if (ft_strstr(str, "$$$ exec p2 : "))
	{
		(*play).en[0] = 'o';
		(*play).en[1] = 'O';
		(*play).my[0] = 'x';
		(*play).my[1] = 'X';
	}
	else if (ft_strstr(str, "$$$ exec p1 : "))
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

int init_info(t_map *obj, int fd)
{
	char	*str;
	char	*save;
	int		i;

	if (get_next_line(fd, &str) != 1)//
		return (0);
	save = ft_strstr(str, " ") + 1;
	(*obj).hmap = ft_atoi(save++);
	save = ft_strstr(save, " ") + 1;
	(*obj).lmap = ft_atoi(save++);
	free(str);
	if (((*obj).map = (int**)malloc(sizeof(int*) * (*obj).hmap)) == NULL)
		return (0);
	i = -1;
	while (++i < (*obj).hmap)
		if (((*obj).map[i] = (int*)malloc(sizeof(int) * (*obj).lmap)) == NULL)
		{
			free_map((obj));
			return (0);
		}
	return (1);
}

int	init_map(t_filler *play, int fd)
{
	char	*str;
	char	*save;
	int		i;

	if (get_next_line(fd, &str) != 1)//
		return (0);
	free(str);
	i = -1;
	while (++i < (*play).map.hmap)
	{
		if (get_next_line(fd, &str) != 1)//
			return (0);
		save = ft_strstr(str, " ");
		if (ft_strlen(save) != (*play).map.lmap + 1)
		{
			free(str);
			return(0);
		}
		if(!fil_map(play, save, i))
		{
			free(str);
			return(0);
		}
	}
	return(1);
}

int	init_figure(t_map *fig, int fd)
{
	char	*str;
	int		i;

	i = -1;
	while (++i < (*fig).hmap)
	{
		if (get_next_line(fd, &str) != 1)//
			return (0);
		if (ft_strlen(str) != (*fig).lmap)
		{
			free(str);
			return(0);
		}
		if(!fil_fig(fig, str, i))
		{
			free(str);
			return(0);
		}
	}
	return(1);
}