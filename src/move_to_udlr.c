/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_udlr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:51:15 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 13:10:23 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_y_to(t_meta *meta, int rate_change)
{
	int		ix;
	int		iy;
	int		index;

	iy = 0;
	while (iy < meta->ysize_map)
	{
		ix = 0;
		while (ix < meta->xsize_map)
		{
			index = (iy * meta->xsize_map) + ix;
			meta->map[index].y += rate_change;
			ft_inside_win(meta, &(meta->map[index]));
			ix++;
		}
		iy++;
	}
}

void	move_x_to(t_meta *meta, int rate_change)
{
	int		ix;
	int		iy;
	int		index;

	iy = 0;
	while (iy < meta->ysize_map)
	{
		ix = 0;
		while (ix < meta->xsize_map)
		{
			index = (iy * meta->xsize_map) + ix;
			meta->map[index].x += rate_change;
			ft_inside_win(meta, &(meta->map[index]));
			ix++;
		}
		iy++;
	}
}
