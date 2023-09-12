/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_relocate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:19:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/12 18:28:14 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_resize(t_meta *meta, int ix, int iy, double scale)
{
	double	total_interval;
	int		index;

	while (iy < meta->ysize_map)
	{
		total_interval = (meta->ysize_map - iy - 1) * meta->interval;
		meta->x_org = (meta->xsize_win / 2) - total_interval;
		meta->y_org = (meta->ysize_win - 2) - (total_interval / sqrt(3));
		ix = 0;
		while (ix < meta->xsize_map)
		{
			index = (iy * meta->xsize_map) + ix;
			meta->map[index].x
				= meta->x_org + ((double)ix * meta->interval);
			meta->map[index].z = (double)(meta->map[index].z * scale);
			meta->map[index].y = meta->y_org
				- ((meta->interval * (double)ix) / sqrt(3))
				- meta->map[index].z;
			meta->map[index].color = meta->map[index].color;
			if (ft_inside_win(meta, &(meta->map[index])) != 0)
				meta->map[index].flag_outwin = 1;
			else
				meta->map[index].flag_outwin = 0;
			ix++;
		}
		iy++;
	}
}

void	ft_mlx_image_clear(t_meta *meta)
{
	ft_bzero(meta->img->addr,
		meta->xsize_map * meta->ysize_map * meta->img->bits_per_pixel);
	mlx_destroy_image(meta->img->mlx, meta->img->img);
	meta->img->img
		= mlx_new_image(meta->img->mlx, meta->xsize_win, meta->ysize_win);
	if (meta->img->img == NULL)
		exit(ft_mes_error("Error. at mlx_img"));
	meta->img->addr
		= mlx_get_data_addr(meta->img->img, &(meta->img->bits_per_pixel),
			&(meta->img->line_length), &(meta->img->endian));
	if (meta->img->addr == NULL)
		exit(ft_mes_error("Error. at mlx_addr"));
}
