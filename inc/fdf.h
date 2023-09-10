/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:00:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/10 14:56:35 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*    include    */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include <errno.h>

/*    for test    */
# include <stdio.h>

/*    define    */

/*    typdef    */
typedef struct s_map
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
	int			flag_outwin;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_puts
{
	double		radian;
	double		radius;
	uint32_t	color;
	double		color_interval[4];
	int			x;
	int			y;
}	t_puts;

typedef struct s_meta
{
	int		xsize_map;
	int		ysize_map;
	int		xsize_win;
	int		ysize_win;
	double	interval;
	int		x_org;
	int		y_org;
	t_map	**map;
	t_mlx	*img;
}	t_meta;

/*    prototype    */
//liborft
char			*get_first_line(int fd);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
size_t			ft_count_word(char *str);
char			**ft_split_multichar(const char *s, const char *multichar);
int				ft_atoi(const char *src);
void			ft_bzero(void *s, size_t n);
char			*ft_atoi_base(char *str, char *base, char *baseto);
//fdf_get_map
t_map			**fdf_get_map(char *filename, t_meta *meta);
//fdf_get_map2
t_map			**ft_allocate_map(int xsize, int ysize);
int				fdf_make_empty_map(char *filename, t_meta *meta);
//ft_free_allocate
int				ft_free_sprit(char **matrix);
int				ft_free_map(t_map **map, const int y);
//ft_print_error
int				ft_print_perror(char *original_message);
int				ft_mes_error(char *message);
//ft_length_utils
double			ft_hypotenus_of_pytgrs(double a, double b);
double			ft_leg_of_rest(double hypotenus, double leg);
double			ft_expand_interval(double window_max, double xsize);
//ft_map_initi_locate
void			ft_conv_data(t_meta *meta, int ix, int iy);
t_meta			*fdf_init_locate_obj(t_meta *meta);
//ft_map_relocate
void			ft_mlx_image_clear(t_meta *meta);
void			ft_resize(t_meta *meta, int ix, int iy, double scale);
//ft_puts_dot
int				ft_puts_all_line(t_meta *meta, t_mlx *img);
//ft_color_get
unsigned char	*ft_color_get(int color, unsigned char *div_color);
//ft_color_gradation
void			ft_get_color_interval(uint32_t from, uint32_t to,
					double interval, double *color_interval);
int				ft_color_gradation(uint32_t from, double *color_interval,
					int repeat);
//ft_mlx_func
void			ft_mlx_pixel_put(t_mlx *meta, int x, int y, int color);
void			ft_draw(t_meta *meta, t_mlx *img);
void			ft_mlx_make_win(t_meta *meta, t_mlx *img);
//ft_mlx_inside_win
int				ft_inside_win(t_meta *meta, t_map *map);
int				ft_which_is_inside(t_map *a, t_map *b);

#endif