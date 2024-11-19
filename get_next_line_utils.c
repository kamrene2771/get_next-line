/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:33 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/19 05:21:21 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}
char	*concat(size_t len, char *dest, char *s)
{
	if (s)
		while (len--)
			*dest++ = *s++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	all_len;
	char	*dest;
	char	*cat;

	s1len = 0;
	s2len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		s1len = ft_strlen(s1);
	if (s2)
		s2len = ft_strlen(s2);
	all_len = s1len + s2len + 1;
	dest = (char *)malloc(all_len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	cat = dest;
	dest = concat(s1len, dest, s1);
	dest = concat(s2len, dest, (char *)s2);
	*dest = '\0';
	return (cat);
}
int	count_nl(char *ptr,ssize_t readbytes)
{
	int	count;
	if (*ptr == '\n' && readbytes == 1)
		return 0;
	count = 0;
	while (*ptr)
	{
		if (*ptr == '\n')
			count++;
		ptr++;
	}
	return (count);
}

char	*copywithmod(char *src ,ssize_t readbytes)
{
	char * dst;
	g_utils.nullter = (char *)malloc((BUFFER_SIZE + count_nl(src,readbytes) + 1) * sizeof(char));
	dst = g_utils.nullter;
	while (*src)
	{
		*dst = *src;
		if (*src == '\n')
		{
			*(++dst) = '\0';
		}else{
			dst++;
		}
		src++;
	}
	*dst = '\0';
	g_utils.toprint = ft_strjoin(g_utils.toprint,g_utils.nullter);
	return g_utils.toprint;
}

void	read_alloc(int fd)
{
	g_utils.i = 0;
	g_utils.ptr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!g_utils.ptr)
		return;
	g_utils.readbytes = read(fd, g_utils.ptr, BUFFER_SIZE);
	if (g_utils.readbytes <= 0 )
	{
		free(g_utils.ptr);
		g_utils.ptr = NULL;
		free(g_utils.nullter);
		g_utils.nullter = NULL;
		return;	
	}
	g_utils.ptr[g_utils.readbytes] = '\0';
	g_utils.toprint = copywithmod(g_utils.ptr,g_utils.readbytes);
	free(g_utils.ptr);
	g_utils.ptr = NULL;
	free(g_utils.nullter);
	g_utils.nullter = NULL;
}
