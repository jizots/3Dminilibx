/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:47:29 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/07 13:47:31 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

size_t	ft_count_word(char *str)
{
	size_t	i;
	size_t	count;
	int		flag;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			if (flag == 1)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (count);
}

// int main()
// {
// 	char *str = " t fwe a	fe80 /. a \n";

// 	printf("%zu\n", ft_count_word(str));
// }