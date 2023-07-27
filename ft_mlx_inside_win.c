/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_inside_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:16:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/25 16:56:14 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_inside_win(t_meta *meta, t_map *map)
{
	if (map->y > meta->ysize_win
		|| map->y < 0)
		return (EXIT_FAILURE);
	if (map->x > meta->xsize_win
		|| map->x < 0)
		return (EXIT_FAILURE);
	return (0);
}

int	ft_which_is_inside(t_map *a, t_map *b)
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
