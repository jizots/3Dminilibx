/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_gradation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:30:58 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/26 17:10:37 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_create_trgb(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	ft_get_color_interval(uint32_t from, uint32_t to,
					double interval, double *color_interval)
{
	unsigned char	c_from[4];
	unsigned char	c_to[4];
	int				i;

	ft_color_get(from, c_from);
	ft_color_get(to, c_to);
	i = 0;
	while (i < 4)
	{
		color_interval[i] = (double)(c_to[i] - c_from[i]) / (double)interval;
		i++;
	}
}

int	ft_color_gradation(uint32_t from, double *color_interval, int repeat)
{
	unsigned char	c_from[4];
	int				color_create;

	ft_color_get(from, c_from);
	color_create
		= ft_create_trgb
		((unsigned char)(c_from[0] + (char)(color_interval[0] * repeat)),
			(unsigned char)(c_from[1] + (char)(color_interval[1] * repeat)),
			(unsigned char)(c_from[2] + (char)(color_interval[2] * repeat)),
			(unsigned char)(c_from[3] + (char)(color_interval[3] * repeat)));
	return (color_create);
}
