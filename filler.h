/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:43:54 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/12 22:33:44 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_map
{
	int			hmap;
	int			lmap;
	int			**map;
}				t_map;

typedef struct s_filler
{
	char		my[2];
	char		en[2];
	t_map		map;
	t_map		figure;
}				t_filler;

int		init_player(t_filler *play, int fd);
int		init_info(t_map *obj, int fd);
int		init_map(t_filler *play, int fd);
int	init_figure(t_map *fig, int fd);

void    free_map(t_map *obj);
int 	test_zero(t_map	*map);
int		chek_zap(t_map *map, int y, int x, int k);

int fil_map(t_filler *play, char *str, int y);
int	fil_fig(t_map *play, char *str, int y);
void	hot_map(t_map *map);

#endif