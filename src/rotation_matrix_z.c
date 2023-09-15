/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix_z.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:28:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 12:09:47 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	convert_x_zaxis(t_map3d *map, double radian)
{
	map->x = map->x * cos(radian) + (map->y * -(sin(radian)));
}

static void	convert_y_zaxis(t_map3d *map, double radian)
{
	map->y = map->x * sin(radian) + (map->y * cos(radian));
}

void	culc_rotation_matrix_z(t_map3d *map, double radian)
{
	convert_x_zaxis(map, radian);
	convert_y_zaxis(map, radian);
}
