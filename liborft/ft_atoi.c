/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:01:46 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/04 17:40:00 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

static size_t	ft_len_isspace3(const char *src)
{
	size_t	len;

	len = 0;
	while (src[len] == ' ' || src[len] == '\f' || src[len] == '\n'
		|| src[len] == '\r' || src[len] == '\t' || src[len] == '\v')
		len++;
	return (len);
}

static int	ft_isminus(const char *src, size_t *i)
{
	if (src[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (src[*i] == '+')
		*i += 1;
	return (0);
}

int	ft_atoi(const char *src)
{
	size_t		i;
	long long	result;
	int			sign_flag;

	i = ft_len_isspace3(src);
	sign_flag = ft_isminus(src, &i);
	result = 0;
	while (src[i] && ('0' <= src[i] && src[i] <= '9'))
	{
		if (sign_flag == 0 && (((LONG_MAX / 10) <= result
					&& ('8' <= src[i] && src[i] <= '9'))
				|| ((LONG_MAX / 10) + 1) <= result))
			return ((int)LONG_MAX);
		if (sign_flag == -1 && (((LONG_MAX / 10) <= result && '9' == src[i])
				|| ((LONG_MAX / 10) + 1) <= result))
			return ((int)LONG_MIN);
		result = result * 10 + (src[i] - '0');
		i++;
	}
	if (sign_flag == -1)
		return (-result);
	return (result);
}

// int main(void)
// {
//     char    str[] = "-9223372036854775809";
//     if (printf("%d\n", atoi(str)) == printf("%d\n", ft_atoi(str)))
//         puts("success");
//     else
//         puts("fault");

// printf ("%d", (int)LONG_MIN);
// }
