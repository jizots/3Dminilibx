/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:29:19 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/24 14:07:41 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

static unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

static unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

static unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

unsigned char	*ft_color_get(int color, unsigned char *div_color)
{
	div_color[0] = get_t(color);
	div_color[1] = get_r(color);
	div_color[2] = get_g(color);
	div_color[3] = get_b(color);
	return (div_color);
}
