/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multichar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:04:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 15:24:35 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

static char	*ft_strtrim_forward(char const *s1, char const *multichar)
{
	char	*start;
	char	*end;
	size_t	len_newstr;
	char	*dest;

	start = (char *) s1;
	while (ft_strchr(multichar, *start) && *start != '\0')
		start += 1;
	if (start != s1 || *start != '\0')
	{
		end = start + 1;
		while (!(ft_strchr(multichar, *end)) && *end != '\0')
			end += 1;
		len_newstr = (size_t)(end - start);
	}
	else
		len_newstr = ft_strlen(start);
	dest = malloc (sizeof(char) * (len_newstr + 1));
	if (dest == NULL)
		return (dest);
	ft_strlcpy (dest, start, len_newstr + 1);
	return (dest);
}

static size_t	num_of_split(const char *s, const char *multichar)
{
	int		i;
	size_t	size_split;

	if (s == NULL)
		return (0);
	size_split = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_strchr(multichar, s[i]))
		{
			size_split++;
			while (!ft_strchr(multichar, s[i]) && s[i] != '\0')
				i++;
		}
		else
			while (ft_strchr(multichar, s[i]) && s[i] != '\0')
				i++;
	}
	return (size_split);
}

static char	*ft_next_str(const char *s, const char *multichar)
{
	char	*next;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_strchr(multichar, s[i]) && s[i] != '\0')
		i++;
	while (!ft_strchr(multichar, s[i]) && s[i] != '\0')
		i++;
	while (ft_strchr(multichar, s[i]) && s[i] != '\0')
		i++;
	next = (char *) &s[i];
	return (next);
}

static char	**ft_setsplit(const char *s,
	const char *multichar, char **box, size_t size_split)
{
	size_t	i;
	char	*start;

	i = 0;
	start = (char *) s;
	while (i < size_split)
	{
		box[i] = ft_strtrim_forward(start, multichar);
		if (box[i] == NULL)
		{
			while (i >= 0)
				free(box[i--]);
			free(box);
			return (NULL);
		}
		i++;
		start = ft_next_str(start, multichar);
	}
	return (box);
}

char	**ft_split_multichar(const char *s, const char *multichar)
{
	char	**box;
	size_t	size_split;

	if (s == NULL)
		return (NULL);
	size_split = num_of_split(s, multichar);
	box = malloc (sizeof(char *) * (size_split + 1));
	if (box == NULL)
		return (box);
	box[size_split] = NULL;
	box = ft_setsplit(s, multichar, box, size_split);
	return (box);
}

// int main()
// {
// 	char	str1[]="      split \n t h i s f or   m e! \n";
// 	char	*cs = " \n";
// 	char	**box;
// 	int		i, k;

// 	box = ft_split_multichar(str1, cs); //check str == NULL
// 	if (box == NULL)
// 	{
// 		puts("error");
// 		return (-1);
// 	}
// 	for (i = 0; box[i] != NULL; i++)
// 	{
// 		k = 0;
// 		if (box[i] == NULL || box[i][k] == '\0')
// 			puts("NULL");
// 		while (box[i][k] != '\0')
// 			write (1, &box[i][k++], 1);
// 		puts("");
// 	}
// 	printf("box[%d] = %p\n", i, box[i]);
// 	i = 0;
// 	while (box[i] != NULL)
// 		free(box[i++]);
// 	free(box);

// 	box = ft_split_multichar("    aa\n              olol", "\n ");
// 	for (i = 0; box[i] != NULL; i++)
// 	{
// 		k = 0;
// 		if (box[i] == NULL || box[i][k] == '\0')
// 			puts("NULL");
// 		while (box[i][k] != '\0')
// 			write (1, &box[i][k++], 1);
// 		puts("");
// 	}
// 	i = 0;
// 	while (box[i] != NULL)
// 		free(box[i++]);
// 	free(box);
// 	return (0);
// }