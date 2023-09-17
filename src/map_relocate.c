/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_relocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:19:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/17 15:47:37 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"

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
			ft_inside_win(meta, &(meta->map[index]));
			ix++;
		}
		iy++;
	}
}

void	rotation_matrix_what(t_meta *meta,
	double radian, void (*f)(t_map3d *, double))
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
			(f)(&(meta->map[index]), radian);
			ft_inside_win(meta, &(meta->map[index]));
			ix++;
		}
		iy++;
	}
}

void	rotate_to_where(int keycode, void *param)
{
	t_meta	*meta;

	meta = param;
	if (keycode == KEY_X)
		rotation_matrix_what(meta, ft_radian(2), culc_rotation_matrix_x);
	else if (keycode == KEY_Y)
		rotation_matrix_what(meta, ft_radian(2), culc_rotation_matrix_y);
	else if (keycode == KEY_Z)
		rotation_matrix_what(meta, ft_radian(2), culc_rotation_matrix_z);
}

void	move_to_where(t_meta *meta, int keycode)
{
	if (keycode == KEY_UP)
		move_y_to(meta, -3);
	else if (keycode == KEY_DOWN)
		move_y_to(meta, 3);
	else if (keycode == KEY_LEFT)
		move_x_to(meta, -3);
	else if (keycode == KEY_RIGHT)
		move_x_to(meta, 3);
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
