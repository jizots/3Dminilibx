/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:42:50 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/24 17:49:41 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

size_t	ft_strlen_base(char *s, char *base)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (s == NULL || base == NULL)
		return (0);
	count = 0;
	while (s[i])
	{
		while (ft_strchr(base, s[i]) == NULL)
			break ;
		count++;
		i++;
	}
	return (count);
}

int	power_lenbase(int lenbase, int power)
{
	int	result;

	result = 1;
	if (!power)
		return (1);
	while (power--)
	{
		result = lenbase * result;
	}
	return (result);
}

int	search_basenum(char c, char *base, int lenbase)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		if (i == lenbase)
			return (-1);
		i++;
	}
	return (i);
}
