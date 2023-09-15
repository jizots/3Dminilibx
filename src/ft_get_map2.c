/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:11:15 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/15 12:05:44 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_char(char *str, char search)
{
	size_t	i;
	int		count;

	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == search)
			count++;
	}
	return (count);
}

int	ft_read_file(int fd, char *buf, int size_buf)
{
	int		byt_rd;
	int		count;

	count = 0;
	byt_rd = 1;
	while (byt_rd)
	{
		byt_rd = read(fd, buf, size_buf - 1);
		if (byt_rd == -1)
		{
			free(buf);
			close(fd);
			return (-1);
		}
		buf[byt_rd] = '\0';
		if (byt_rd > 0)
			count += ft_count_char(buf, '\n');
	}
	return (count);
}

int	ft_count_line(int fd, char *filename)
{
	int		count;
	char	*buf;
	int		size_buf;

	if (fd == -1)
	{
		ft_print_perror(filename);
		return (-1);
	}
	size_buf = 6;
	buf = malloc (sizeof(char) * size_buf);
	if (buf == NULL)
	{
		close (fd);
		return (-1);
	}
	count = ft_read_file(fd, buf, size_buf);
	if (count == -1)
		return (ft_print_perror("map file"));
	if (close(fd) == -1)
		perror("close");
	free (buf);
	return (count + 1);
}

t_map3d	*ft_allocate_map(int xsize, int ysize)
{
	t_map3d	*map;

	map = malloc(sizeof(t_map3d) * (ysize * xsize));
	if (map == NULL)
		return (NULL);
	return (map);
}

int	fdf_make_empty_map(char *filename, t_meta *meta)
{
	int		fd;
	char	*line_first;

	meta->ysize_map = ft_count_line(open(filename, O_RDONLY), filename);
	if (meta->ysize_map == -1)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_print_perror(filename));
	line_first = get_first_line(fd);
	if (line_first == NULL)
		return (ft_mes_error("Fail gnl\n"));
	if (close(fd) == -1)
		perror(filename);
	meta->xsize_map = ft_count_word(line_first);
	free (line_first);
	if (meta->xsize_map == 0)
		return (ft_mes_error("No data or Data start from newline\n"));
	meta->map = ft_allocate_map(meta->xsize_map, meta->ysize_map);
	if (meta->map == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
