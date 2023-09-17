/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_allocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:40:12 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/12 12:30:02 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
