/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:33:41 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 14:21:51 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*heapadd;
	size_t		i;

	if (size != 0 && LONG_MAX / size < nmemb)
		return (NULL);
	heapadd = malloc (size * nmemb);
	if (heapadd == NULL)
		return (heapadd);
	i = 0;
	while (i < size * nmemb)
		heapadd[i++] = 0;
	return ((void *) heapadd);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	str = (unsigned char *) s;
	c1 = (unsigned char) c;
	if (n == 0 || s == NULL)
		return (NULL);
	i = 0;
	while (i < n && str[i] != c1)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void *) &str[i]);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (dest == NULL)
		return (size + len_s);
	len_d = ft_strlen(dest);
	if (size <= len_d)
		return (size + len_s);
	while (*dest)
		dest++;
	while (size - len_d - 1)
	{
		*dest++ = *src++;
		size--;
		if (*src == '\0')
			break ;
	}
	*dest = '\0';
	return (len_d + len_s);
}

int	ft_createline_nobuf(char **save, char **s_nl, char *flag)
{
	size_t	i_nl;
	char	*s_tmp;

	if (flag == NULL)
		return (0);
	s_tmp = *save;
	i_nl = flag - &s_tmp[0];
	*s_nl = (char *) ft_calloc((i_nl + 1) + 1, sizeof(char));
	if (*s_nl == NULL)
		return (-1);
	ft_strlcat(*s_nl, s_tmp, (i_nl + 1) + 1);
	if (ft_strlen(s_tmp) == (i_nl + 1))
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	*save = (char *) ft_calloc(ft_strlen(&s_tmp[i_nl + 1]) + 1, sizeof(char));
	if (*save == NULL)
		return (-1);
	else
		ft_strlcat(*save, &s_tmp[i_nl + 1], ft_strlen(&s_tmp[i_nl + 1]) + 1);
	free(s_tmp);
	return (0);
}
