/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:56:28 by boris             #+#    #+#             */
/*   Updated: 2019/09/19 17:19:38 by boris            ###   ########.fr       */
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
}				t_map;

typedef struct	s_position
{
	int			x;
	int			y;
	int			min;
}				t_position;

typedef struct	s_filler
{
	char		my[2];
	char		en[2];
	t_map		map;
	t_map		piece;
	t_position	position;
}				t_filler;

#endif