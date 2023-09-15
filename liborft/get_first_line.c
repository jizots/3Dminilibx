/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:49:18 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/14 15:36:46 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

static char	*ft_free_str(char *str)
{
	free(str);
	return (NULL);
}

static int	ft_join(char *buf, char *end, char **s_nl)
{
	char	*tmp;

	tmp = *s_nl;
	*s_nl = malloc(sizeof(char) * ((end - buf + 1) + ft_strlen(*s_nl) + 1));
	if (*s_nl == NULL)
	{
		free (tmp);
		return (-1);
	}
	ft_strlcpy(*s_nl, tmp, ft_strlen(tmp) + 1);
	ft_strlcat(*s_nl, buf, ((end - buf + 1) + ft_strlen(*s_nl) + 1));
	free (tmp);
	return (0);
}

static int	ft_delimicheck(char *buf, int byte_rd, char **s_nl)
{
	char	*p_nwl;

	p_nwl = ft_strchr(buf, '\n');
	if (p_nwl == NULL)
	{
		if (ft_join(buf, &buf[byte_rd], s_nl) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (ft_join(buf, p_nwl, s_nl) == -1)
			return (-1);
	}
	return (0);
}

static char	*ft_get_next_buf(int fd, char *buf)
{
	char	*s_nl;
	int		byte_rd;
	int		flag;

	s_nl = NULL;
	byte_rd = 1;
	while (byte_rd)
	{
		byte_rd = read(fd, buf, BUFFER_SIZE);
		if (byte_rd == -1)
			return (ft_free_str(buf));
		buf[byte_rd] = '\0';
		flag = ft_delimicheck(buf, byte_rd, &s_nl);
		if (flag == -1)
			return (ft_free_str(buf));
		else if (flag == 0)
			break ;
	}
	free(buf);
	return (s_nl);
}

char	*get_first_line(int fd)
{
	char	*buf;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	return (ft_get_next_buf(fd, buf));
}

// int main()
// {
// 	char *line;
// 	int fd;
// 	fd = open("/Users/sotanaka/fdf-0/test_map3ds/pnp_flat.fdf", O_RDONLY);
// 	line = get_first_line(fd);
// 	if (line == NULL)
// 		puts("error");
// 	printf ("result->%s<-\n", line);
// 	free(line);
// }
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }