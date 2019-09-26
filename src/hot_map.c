/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:33:25 by boris             #+#    #+#             */
/*   Updated: 2019/09/26 20:31:05 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			read_map(t_filler *data)
{
	int		ret;
	char	*line;

	while (data->map.cur_hmap != data->map.hmap &&
		(ret = get_next_line(0, &line)))
	{
		if (ret == -1)
		{
			perror("VM Output Read Error");
			return (0);
		}
		if (ismapline(line))
		{
			if (!(fill_map(data, line + 4)))
			{
				free(line);
				return (0);
			}
			data->map.cur_hmap++;
		}
		free(line);
	}
	return (1);
}

int			ismapline(char *line)
{
	if (ft_strchr(line, '.') || ft_strchr(line, '*') || ft_strchr(line, 'O') ||
		ft_strchr(line, 'o') || ft_strchr(line, 'x') || ft_strchr(line, 'X'))
		return (1);
	return (0);
}

int			fill_map(t_filler *data, char *line)
{
	int i;

	if (ft_strlen(line) != data->map.lmap)
	{
		perror("Invalid Map");
		return (0);
	}
	i = -1;
	while (++i < data->map.lmap)
	{
		if (line[i] == '.')
			data->map.map[data->map.cur_hmap][i] = 0;
		else if (line[i] == data->my[0] || line[i] == data->my[1])
			data->map.map[data->map.cur_hmap][i] = -2;
		else if (line[i] == data->en[0] || line[i] == data->en[1])
			data->map.map[data->map.cur_hmap][i] = -1;
		else
		{
			perror("Invalid Map");
			return (0);
		}
	}
	return (1);
}

long int	take_sum(t_filler *data, int y, int x)
{
	int			i;
	int			j;
	long int	k;

	k = 0;
	i = -1;
	while (++i < data->piece.hmap)
	{
		j = -1;
		while (++j < data->piece.lmap)
			k += data->piece.map[i][j] * data->map.map[i + y][j + x];
	}
	return (k);
}
