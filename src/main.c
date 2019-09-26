/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:13:57 by boris             #+#    #+#             */
/*   Updated: 2019/09/26 20:46:38 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		read_all(t_filler *data, char *line)
{
	if (ft_strstr(line, "$$$"))
	{
		if (!init_player(data, line))
			return (0);
	}
	else if (ft_strstr(line, "Plateau"))
	{
		if (!init_plateau(data, line))
			return (0);
	}
	else if (ft_strstr(line, "Piece"))
	{
		if (!init_piece(data, line))
			return (0);
		push_piece(data);
		print_rez(&(data->position));
		init_position(&(data->position));
		free_map(&(data->piece));
	}
	return (1);
}

void	print_rez(t_position *position)
{
	char	*c;

	c = ft_itoa(position->y);
	write(1, c, ft_strlen(c));
	write(1, " ", 1);
	free(c);
	c = ft_itoa(position->x);
	write(1, c, ft_strlen(c));
	write(1, "\n", 1);
	free(c);
}

int		main(void)
{
	t_filler	data;
	char		*line;
	int			ret;

	init_data(&data);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
		{
			perror("VM Output Read Error");
			free(line);
			break ;
		}
		if (!read_all(&data, line))
		{
			free(line);
			break ;
		}
		free(line);
	}
	free_map(&(data.map));
	free_map(&(data.piece));
	return (0);
}
