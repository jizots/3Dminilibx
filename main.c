/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:42:02 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/26 18:08:25 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_meta	meta;
	t_meta	meta_conv;
	t_mlx	img;

	if (ac != 2)
		write(1, "Entry like './fdf filepath'\n", 28);
	else
	{
		meta.img = &img;
		meta.xsize_win = 1000;
		meta.ysize_win = 1000;
		meta.map = ft_get_map(av[1], &meta);
		if (meta.map == NULL)
			return (1);
		if (meta.map != NULL)
		{
			ft_initi_locate_obj(&meta, &meta_conv);
			ft_mlx_make_win(&meta_conv, &img);
			ft_free_map(meta.map, meta.ysize_map);
			ft_free_map(meta_conv.map, meta_conv.ysize_map);
		}
	}
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q fdf");
// }