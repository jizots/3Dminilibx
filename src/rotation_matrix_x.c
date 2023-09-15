/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:28:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 12:10:38 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	convert_y_xaxis(t_map3d *map, double radian)
{
	map->y = map->y * cos(radian) + (map->z * -(sin(radian)));
}

static void	convert_z_xaxis(t_map3d *map, double radian)
{
	map->z = map->y * sin(radian) + (map->z * cos(radian));
}

void	culc_rotation_matrix_x(t_map3d *map, double radian)
{
	map->y -= 998;
	convert_y_xaxis(map, radian);
	convert_z_xaxis(map, radian);
	map->y += 998;
}
