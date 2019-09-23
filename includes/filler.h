/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:56:28 by boris             #+#    #+#             */
/*   Updated: 2019/09/23 20:56:51 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#	define FILLER_H

#	include "../libft/libft.h"
#	include <stdio.h>
#	include <errno.h>
int fd;
typedef struct			s_map
{
	int					hmap;
	int					lmap;
	int					**map;
	int					cur_hmap;
}						t_map;

typedef struct			s_position
{
	int					x;
	int					y;
	long int			min;
	int					first;
}						t_position;

typedef struct			s_filler
{
	char				my[2];
	char				en[2];
	t_map				map;
	t_map				piece;
	t_position			position;
}						t_filler;

void	init_map(t_map *map);
void	init_position(t_position *position);
void	init_data(t_filler *data);
int		init_player(t_filler *data, char *line);
int		init_plateau(t_filler *data, char *line);

int		read_map(t_filler *map);
int		fill_map(t_filler *data, char *line);
int		ismapline(char *line);
long int	take_sum(t_filler *data, int y, int x);

int	init_piece(t_filler *data, char *line);
int	read_piece(t_filler *data);
int	fill_piece(t_filler *data, char *line);
void	fill_position(t_filler *data, int y, int x, long int min);

void	hot_map(t_map *map);
int		test_zeros(t_map *map);
int		chek_place(t_map *map, int y, int x, int k);
void	push_piece(t_filler *data);
int		chek_minus(t_filler *data, int y, int x);

void	free_map(t_map *map);

#endif