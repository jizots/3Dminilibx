/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_inside_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:16:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 13:10:57 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_inside_win(t_meta *meta, t_map3d *map)
{
	if (map->y > meta->ysize_win
		|| map->y < 0)
		map->flag_outwin = 1;
	if (map->x > meta->xsize_win
		|| map->x < 0)
		map->flag_outwin = 1;
	map->flag_outwin = 0;
}

int	ft_which_is_inside(t_map3d *a, t_map3d *b)
{
	int	flag;

	flag = 0;
	if (a->flag_outwin == EXIT_FAILURE && b->flag_outwin == 0)
		flag = 1;
	else if (a->flag_outwin == 0 && b->flag_outwin == EXIT_FAILURE)
		flag = 2;
	else if (a->flag_outwin == EXIT_FAILURE && b->flag_outwin == EXIT_FAILURE)
		flag = 3;
	return (flag);
}
