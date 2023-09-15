/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:42:02 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 12:11:05 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_sizeof_window(t_meta *meta, t_mlx *img)
{
	meta->xsize_win = 1000;
	meta->ysize_win = 1000;
	meta->img = img;
}

int	main(int ac, char **av)
{
	t_meta	meta;
	t_mlx	img;

	if (ac != 2)
		write(1, "Entry like './fdf filepath'\n", 28);
	else
	{
		init_sizeof_window(&meta, &img);
		meta.map = fdf_get_map3d(av[1], &meta);
		if (meta.map == NULL)
			return (1);
		if (meta.map != NULL)
		{
			fdf_init_locate_obj(&meta);
			ft_mlx_make_win(&meta, &img);
			free(meta.map);
		}
	}
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q fdf");
// }