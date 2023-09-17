/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:22:29 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/17 15:50:14 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"

void	ft_mlx_pixel_put(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_mlx_close_win(void *param)
{
	t_mlx	*img;

	img = param;
	mlx_destroy_window(img->mlx, img->win);
	exit (0);
}

int	ft_mlx_keypush(int keycode, void *param)
{
	t_meta	*meta;

	meta = param;
	if (keycode == KEY_ESC)
		return (ft_mlx_close_win(meta->img));
	else if (keycode == KEY_PLUS)
	{
		meta->interval = meta->interval * 1.1111;
		ft_resize(meta, 0, 0, 1.1111);
	}
	else if (keycode == KEY_MINUS)
	{
		meta->interval = meta->interval * 0.9;
		ft_resize(meta, 0, 0, 0.9);
	}
	else if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		rotate_to_where(keycode, param);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move_to_where(meta, keycode);
	ft_mlx_image_clear(meta);
	ft_draw(meta, meta->img);
	return (0);
}

void	ft_mlx_make_win(t_meta *meta, t_mlx *img)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		exit(ft_mes_error("Error. at mlx_int"));
	img->win
		= mlx_new_window(img->mlx, meta->xsize_win, meta->ysize_win, "mfdf");
	if (img->win == NULL)
		exit(ft_mes_error("Error. at mlx_win"));
	img->img = mlx_new_image(img->mlx, meta->xsize_win, meta->ysize_win);
	if (img->img == NULL)
		exit(ft_mes_error("Error. at mlx_img"));
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (img->addr == NULL)
		exit(ft_mes_error("Error. at mlx_addr"));
	ft_draw(meta, img);
}
