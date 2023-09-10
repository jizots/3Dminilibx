/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_initi_locate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:20:09 by hotph             #+#    #+#             */
/*   Updated: 2023/09/10 14:55:06 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_conv_data(t_meta *meta, int ix, int iy)
{
	double	total_interval;

	while (iy < meta->ysize_map)
	{
		total_interval = (meta->ysize_map - iy - 1) * meta->interval;
		meta->x_org = (meta->xsize_win / 2) - total_interval;
		meta->y_org = (meta->ysize_win - 2) - (total_interval / sqrt(3));
		ix = 0;
		while (ix < meta->xsize_map)
		{
			meta->map[iy][ix].x
				= (double)meta->x_org + (ix * meta->interval);
			meta->map[iy][ix].z = (double)(meta->map[iy][ix].z
					* ((meta->interval / sqrt(3)) * 2));
			meta->map[iy][ix].y = (double)meta->y_org
				- ((meta->interval * ix) / sqrt(3)) - meta->map[iy][ix].z;
			meta->map[iy][ix].color = meta->map[iy][ix].color;
			if (ft_inside_win(meta, &(meta->map[iy][ix])) != 0)
				meta->map[iy][ix].flag_outwin = 1;
			ix++;
		}
		iy++;
	}
}

t_meta	*fdf_init_locate_obj(t_meta *meta)
{
	meta->interval = ft_expand_interval(meta->xsize_win, meta->xsize_map);
	ft_conv_data(meta, 0, 0);
	return (meta);
}
