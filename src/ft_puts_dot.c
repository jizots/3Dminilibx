/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:35:01 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/12 18:20:56 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_puts_line(t_meta *meta, t_map *from, t_map *to, t_mlx *img)
{
	t_puts	a;

	a.radius = ft_hypotenus_of_pytgrs(to->x - from->x, to->y - from->y);
	a.radian = atan2((to->y - from->y), (to->x - from->x));
	ft_get_color_interval
		(from->color, to->color, (int)a.radius, a.color_interval);
	while (a.radius >= 0)
	{
		a.color
			= ft_color_gradation(from->color, a.color_interval, (int)a.radius);
		a.x = from->x + (a.radius * cos(a.radian));
		a.y = from->y + (a.radius * sin(a.radian));
		if ((0 <= a.x && a.x < meta->xsize_win)
			&& (0 <= a.y && a.y < meta->ysize_win))
			ft_mlx_pixel_put(img, a.x, a.y, a.color);
		else
			break ;
		a.radius--;
	}
	return (0);
}

void	ft_puts_line_yaxis(t_meta *meta, t_mlx *img)
{
	int	x;
	int	y;
	int	flag;
	int	index;

	y = 0;
	while (y < meta->ysize_map - 1)
	{
		x = 0;
		while (x < meta->xsize_map)
		{
			index = (y * meta->xsize_map) + x;
			flag = ft_which_is_inside
				(&(meta->map[index]), &(meta->map[(index + meta->xsize_map)]));
			if (flag <= 1)
				ft_puts_line
					(meta, &(meta->map[index]), &(meta->map[(index + meta->xsize_map)]), img);
			else if (flag == 2)
				ft_puts_line
					(meta, &(meta->map[(index + meta->xsize_map)]), &(meta->map[index]), img);
			x++;
		}
		y++;
	}
}

int	ft_puts_all_line(t_meta *meta, t_mlx *img)
{
	int	x;
	int	y;
	int	flag;
	int	index;

	y = 0;
	while (y < meta->ysize_map)
	{
		x = 0;
		while (x < meta->xsize_map - 1)
		{
			index = (y * meta->xsize_map) + x;
			flag = ft_which_is_inside
				(&(meta->map[index]), &(meta->map[index + 1]));
			if (flag <= 1)
				ft_puts_line
					(meta, &(meta->map[index]), &(meta->map[index + 1]), img);
			else if (flag == 2)
				ft_puts_line
					(meta, &(meta->map[index + 1]), &(meta->map[index]), img);
			x++;
		}
		y++;
	}
	ft_puts_line_yaxis(meta, img);
	return (0);
}
