/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:37 by boris             #+#    #+#             */
/*   Updated: 2019/09/10 11:13:27 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	init_player(t_filler play)
{
	char *str;

	if (get_next_line(0, &str) != 1)
		return (0);
	if (ft_strstr(str, "p1"))
	{
		play.en[0] = 'o';
		play.en[1] = 'O';
		play.my[0] = 'x';
		play.my[1] = 'X';
	}
	else if (ft_strstr(str, "p1"))
	{
		play.en[0] = 'x';
		play.en[1] = 'X';
		play.my[0] = 'o';
		play.my[1] = 'O';
	}
	else
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);  
}