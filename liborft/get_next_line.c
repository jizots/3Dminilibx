/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:49:18 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/24 17:54:51 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

int	ft_createline_tos_nl(char *buf, char **save, int byte_rd, char **s_nl)
{
	char	*flag;
	size_t	i_nl;
	char	*s_tmp;

	s_tmp = *save;
	flag = ft_memchr(buf, '\n', byte_rd);
	i_nl = flag - &buf[0];
	*s_nl = (char *) ft_calloc(ft_strlen(s_tmp) + (i_nl + 1) + 1, sizeof(char));
	if (*s_nl == NULL)
		return (-1);
	ft_strlcat(*s_nl, s_tmp, ft_strlen(s_tmp) + 1);
	ft_strlcat(*s_nl, buf, ft_strlen(s_tmp) + (i_nl + 1) + 1);
	*save = (char *) ft_calloc(ft_strlen(&buf[i_nl + 1]) + 1, sizeof(char));
	if (*save == NULL)
		return (-1);
	if (ft_strlen(buf) == (i_nl + 1))
	{
		free(*save);
		*save = NULL;
	}
	else
		ft_strlcat(*save, &buf[i_nl + 1], ft_strlen(&buf[i_nl + 1]) + 1);
	free(s_tmp);
	return (0);
}

int	ft_createline_withbuf(char *buf, int byte_rd, char **save, char **s_nl)
{
	char	*flag;

	flag = ft_memchr(buf, '\n', byte_rd);
	if (flag == NULL)
	{
		*s_nl = (char *) ft_calloc
			((ft_strlen(*save) + byte_rd + 1), sizeof(char));
		if (*s_nl == NULL)
			return (-1);
		ft_strlcat(*s_nl, *save, ft_strlen(*save) + 1);
		ft_strlcat(*s_nl, buf, (ft_strlen(*save) + byte_rd + 1));
		free(*save);
		*save = *s_nl;
		*s_nl = NULL;
	}
	else if (*flag == '\n')
	{
		if (ft_createline_tos_nl(buf, save, byte_rd, s_nl) == -1)
			return (-1);
	}
	return (0);
}

int	ft_delimicheck_and_branch(char *buf, int byte_rd, char **save, char **s_nl)
{
	char	*flag;

	*s_nl = NULL;
	if (byte_rd == 0)
	{
		flag = ft_memchr(*save, '\n', ft_strlen(*save));
		if (ft_createline_nobuf(save, s_nl, flag) == -1)
		{
			if (*save != NULL)
				free(*save);
			return (-1);
		}
	}
	else
	{
		if (ft_createline_withbuf(buf, byte_rd, save, s_nl) == -1)
		{
			if (*save != NULL)
				free(*save);
			return (-1);
		}
	}
	return (0);
}

char	*get_next_buf(int fd, char **save, char *buf, int byte_rd)
{
	char	*s_nl;

	while (1)
	{
		byte_rd = read(fd, buf, BUFFER_SIZE);
		if (byte_rd <= 0)
		{
			free(buf);
			if (byte_rd == 0 && *save != NULL)
			{
				s_nl = *save;
				*save = NULL;
				return (s_nl);
			}
			return (NULL);
		}
		buf[byte_rd] = '\0';
		if (ft_delimicheck_and_branch(buf, byte_rd, save, &s_nl) == -1)
			return (NULL);
		if (s_nl != NULL)
		{
			free(buf);
			return (s_nl);
		}
	}
}

char	*get_next_line(int fd)
{
	char		*s_nl;
	static char	*save;
	int			byte_rd;
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	byte_rd = 0;
	if (save != NULL)
	{
		if (ft_delimicheck_and_branch(NULL, byte_rd, &save, &s_nl) == -1)
			return (NULL);
		if (s_nl != NULL)
			return (s_nl);
	}
	buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	return (get_next_buf(fd, &save, buf, byte_rd));
}

// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("/Users/sotanaka/fdf-0/test_maps/pnp_flat.fdf", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf ("result->%s<-\n", line);
// 		free(line);
// 	}

// }
