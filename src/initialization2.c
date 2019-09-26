/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:58:26 by boris             #+#    #+#             */
/*   Updated: 2019/09/26 20:31:04 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		init_piece(t_filler *data, char *line)
{
	data->piece.hmap = ft_atoi(ft_strstr(line, " ") + 1);
	data->piece.lmap = ft_atoi(ft_strstr((ft_strstr(line, " ") + 1), " ") + 1);
	if (!(data->piece.map = (int**)ft_memalloc(sizeof(int*) *
			(data->piece.hmap + 1))))
	{
		perror("Memory Allocation Error");
		return (0);
	}
	data->piece.cur_hmap = -1;
	while (++(data->piece.cur_hmap) < data->piece.hmap)
		if (!(data->piece.map[data->piece.cur_hmap] =
		(int*)ft_memalloc(sizeof(int) * data->piece.lmap)))
		{
			perror("Memory Allocation Error");
			return (0);
		}
	data->piece.cur_hmap = 0;
	if (!(read_piece(data)))
		return (0);
	return (1);
}

int		read_piece(t_filler *data)
{
	int		ret;
	char	*line;

	while (data->piece.cur_hmap != data->piece.hmap &&
		(ret = get_next_line(0, &line)))
	{
		if (ret == -1)
		{
			perror("VM Output Read Error");
			return (0);
		}
		if (ismapline(line))
		{
			if (!(fill_piece(data, line)))
			{
				free(line);
				return (0);
			}
			data->piece.cur_hmap++;
		}
		free(line);
	}
	return (1);
}

int		fill_piece(t_filler *data, char *line)
{
	int i;

	if (ft_strlen(line) != data->piece.lmap)
	{
		perror("Invalid Map");
		return (0);
	}
	i = -1;
	while (++i < data->piece.lmap)
	{
		if (line[i] == '.')
			data->piece.map[data->piece.cur_hmap][i] = 0;
		else if (line[i] == '*')
			data->piece.map[data->piece.cur_hmap][i] = 1;
		else
		{
			perror("Invalid Map");
			return (0);
		}
	}
	return (1);
}

void	fill_position(t_filler *data, int y, int x, long int min)
{
	data->position.min = min;
	data->position.x = x;
	data->position.y = y;
}
