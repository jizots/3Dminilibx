/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_allocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:40:12 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/20 17:29:52 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_free_map(t_map **map, const int y)
{
	int	iy;

	iy = 0;
	while (iy < y)
	{
		free(map[iy]);
		iy++;
	}
	free(map);
	return (EXIT_FAILURE);
}

int	ft_free_sprit(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i++]);
	}
	free(matrix);
	return (EXIT_FAILURE);
}
