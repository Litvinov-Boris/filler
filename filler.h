/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:43:54 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/11 19:24:58 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_filler
{
	char		my[2];
	char		en[2];
	int			hmap;
	int			lmap;
	int			**map;
}				t_filler;

int		init_player(t_filler *play, int fd);
int		init_map_info(t_filler *play, int fd);
int	init_map(t_filler *play, int fd);

void    free_map(t_filler *play);

int fil_map(t_filler *play, char *str, int y);

#endif