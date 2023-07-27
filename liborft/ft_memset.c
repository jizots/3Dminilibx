/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:04:40 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/26 14:15:44 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	char			*dest;
	size_t			i;

	uc = (unsigned char) c;
	dest = (char *) b;
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = uc;
		i++;
	}
	return (b);
}

// int main()
// {
//     char    str1[]="10293jfoefjo";
//     char    str2[]="10293jfoefjo";
// 	int i=8;

//     printf("%s\n", memset(str1, 65, i));
//     printf("%s\n", ft_memset(str2, 65, i));
// }
