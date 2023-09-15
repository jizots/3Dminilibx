/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:09:55 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 12:05:56 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_str_conv_data(char *str, t_meta *meta, int ix, int iy)
{
	char		*tmp;
	uint32_t	color;
	int			i;

	i = 0;
	color = 0xFFFFFF;
	while (str[i])
	{
		if (str[i] == ',')
		{
			tmp = ft_atoi_base(&str[i + 3], "0123456789abcdef", "0123456789");
			if (tmp == NULL)
				return (ft_print_perror("allocate(atoi_base)"));
			color = ft_atoi(tmp);
			free(tmp);
			break ;
		}
		else
			i++;
	}
	meta->map[(iy * meta->xsize_map) + ix]
		= (t_map3d){(double)ix, (double)iy, (double)ft_atoi(str), color, 0};
	return (EXIT_SUCCESS);
}

static int	ft_line_convert_data(char *line, t_meta *meta, const int y)
{
	int		ix;
	char	**matrix;

	matrix = ft_split_multichar(line, " \n");
	if (matrix == NULL)
		return (EXIT_FAILURE);
	ix = 0;
	while (matrix[ix] != NULL)
		ix++;
	if (ix != meta->xsize_map)
	{
		ft_free_sprit(matrix);
		return (ft_mes_error("Wrong line existing.\n"));
	}
	ix = 0;
	while (matrix[ix] != NULL)
	{
		if (ft_str_conv_data(matrix[ix], meta, ix, y) != EXIT_SUCCESS)
			return (ft_free_sprit(matrix));
		ix++;
	}
	ft_free_sprit(matrix);
	return (EXIT_SUCCESS);
}

static int	ft_get_line(int fd, t_meta *meta)
{
	int		iy;
	char	*line;

	iy = 0;
	while (iy < meta->ysize_map)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_line_convert_data(line, meta, (const int) iy)
			!= EXIT_SUCCESS)
			return (EXIT_FAILURE);
		free(line);
		iy++;
	}
	if (iy != meta->ysize_map)
		return (ft_mes_error("Wrong line existing.\n"));
	return (EXIT_SUCCESS);
}

t_map3d	*fdf_get_map3d(char *filename, t_meta *meta)
{
	int		fd;

	if (fdf_make_empty_map(filename, meta) != 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_perror("open :");
		return (NULL);
	}
	if (ft_get_line(fd, meta) != 0)
	{
		free(meta->map);
		return (NULL);
	}
	close (fd);
	return (meta->map);
}
