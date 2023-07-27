/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liborft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:49:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/26 14:14:25 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBORFT_H
# define LIBORFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
//for func
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

//for verify
# include <stdio.h>

//define

//struct

//prototype
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*get_first_line(int fd);
int		ft_createline_nobuf(char **s_save, char **s_new, char *flag);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *src);
size_t	ft_strlen_base(char *s, char *base);
int		power_lenbase(int lenbase, int power);
int		search_basenum(char c, char *base, int lenbase);
char	*ft_atoi_base(char *str, char *base, char *baseto);

#endif
