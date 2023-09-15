/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:28:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 12:09:34 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	convert_x_yaxis(t_map3d *map, double radian)
{
	map->x = map->x * cos(radian) + (map->z * sin(radian));
}

static void	convert_z_yaxis(t_map3d *map, double radian)
{
	map->z = map->x * -(sin(radian)) + (map->z * cos(radian));
}

void	culc_rotation_matrix_y(t_map3d *map, double radian)
{
	map->x -= 500;
	convert_x_yaxis(map, radian);
	convert_z_yaxis(map, radian);
	map->x += 500;
}
