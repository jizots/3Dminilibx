/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:10:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/23 14:38:40 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_radian(double theta)
{
	return (theta * (M_PI / 180));
}

double	ft_distance_of_point(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

double	ft_hypotenus_of_pytgrs(double a, double b)
{
	return (sqrt(pow(a, 2) + pow(b, 2)));
}

double	ft_leg_of_rest(double hypotenus, double leg)
{
	return (sqrt(pow(hypotenus, 2) - pow(leg, 2)));
}

double	ft_expand_interval(double xsize_win, double xsize_obj)
{
	double	expanded;

	expanded = (xsize_win / 2) / xsize_obj;
	return (expanded);
}

// int main()
// {
// 	double	x;
// 	double	y;

// 	printf("expanded: %f\n", ft_expand_dot_interval(100, 50));
// }