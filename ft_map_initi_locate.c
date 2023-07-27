/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_initi_locate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:20:09 by hotph             #+#    #+#             */
/*   Updated: 2023/07/26 17:27:45 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_conv_data(t_meta *meta, t_meta *meta_c, int ix, int iy)
{
	double	total_interval;

	while (iy < meta->ysize_map)
	{
		total_interval = (meta->ysize_map - iy - 1) * meta_c->interval;
		meta_c->x_org = (meta->xsize_win / 2) - total_interval;
		meta_c->y_org = (meta->ysize_win - 2) - (total_interval / sqrt(3));
		ix = 0;
		while (ix < meta->xsize_map)
		{
			meta_c->map[iy][ix].x
				= (double)meta_c->x_org + (ix * meta_c->interval);
			meta_c->map[iy][ix].z = (double)(meta->map[iy][ix].z
					* ((meta_c->interval / sqrt(3)) * 2));
			meta_c->map[iy][ix].y = (double)meta_c->y_org
				- ((meta_c->interval * ix) / sqrt(3)) - meta_c->map[iy][ix].z;
			meta_c->map[iy][ix].color = meta->map[iy][ix].color;
			if (ft_inside_win(meta_c, &(meta_c->map[iy][ix])) != 0)
				meta_c->map[iy][ix].flag_outwin = 1;
			ix++;
		}
		iy++;
	}
}

t_meta	*ft_initi_locate_obj(t_meta *meta, t_meta *meta_c)
{
	meta->interval = ft_expand_interval(meta->xsize_win, meta->xsize_map);
	*meta_c = *meta;
	if (ft_allocate_map(meta_c) == NULL)
		return (NULL);
	ft_conv_data(meta, meta_c, 0, 0);
	return (meta_c);
}
