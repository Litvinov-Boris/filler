/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:56:28 by boris             #+#    #+#             */
/*   Updated: 2019/09/19 21:09:06 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#	define FILLER_H

#	include "../libft/libft.h"
#	include <stdio.h>
#	include <errno.h>

typedef struct	s_map
{
	int			hmap;
	int			lmap;
	int			**map;
	int			cur_hmap;
}				t_map;

typedef struct	s_position
{
	int			x;
	int			y;
	int			min;
	int			first;
}				t_position;

typedef struct	s_filler
{
	char		my[2];
	char		en[2];
	t_map		map;
	t_map		piece;
	t_position	position;
}				t_filler;

void	init_map(t_map *map);
void	init_position(t_position *position);
void	init_data(t_filler *data);
int		init_player(t_filler *data, char *line);

#endif