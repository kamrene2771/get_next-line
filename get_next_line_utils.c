/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:33 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/20 08:12:45 by kamrene          ###   ########.fr       */
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
char	*concat(char *dest, char *s)
{
	if (s)
		while (*s)
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
	dest = concat(dest, s1);
	dest = concat(dest,	s2);
	*dest = '\0';
	return (cat);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*sub;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start)
		len = 0;
	else if (len > str_len - start)
		len = str_len - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	sub = dest;
	s += start;
	while (len)
	{
		*dest++ = *s++;
		len--;
	}
	*dest = '\0';
	return (sub);
}
int checknl(char *ptr){
	int len = 0;
	char *tofree = NULL;
	int count=0;
	while(*ptr){
		len++;
		if (*ptr == '\n'){
			count++;
			break;
		}
		ptr++;
	}
	if(g_utils.readbytes > 0)
		g_utils.temp = g_utils.ptr;
	else
		g_utils.ptr = g_utils.temp;
	
	if(count == 0)
		return 0;
		
	tofree = g_utils.ptr;
	g_utils.ptr = ft_substr(ptr,0,len);
	if(tofree)
		free(tofree);
	g_utils.temp += len;
	
	
	return count;
}
void freeptr()
{
	free(g_utils.ptr);
	g_utils.ptr = NULL;	
}
void	read_alloc(int fd)
{
	char *temp;
	g_utils.ptr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!g_utils.ptr)
		return;
	g_utils.readbytes = read(fd, g_utils.ptr, BUFFER_SIZE);
	
	if (g_utils.readbytes <= 0 && *g_utils.temp == '\0'){			
		return freeptr();
	}
	g_utils.ptr[g_utils.readbytes] = '\0';
	if (checknl(g_utils.ptr) > 0)
		g_utils.readbytes = 0;
	temp = g_utils.takenull;
	g_utils.takenull = ft_strjoin(g_utils.takenull,g_utils.ptr);
	if (temp)
        free(temp);
	freeptr();
	g_utils.toprint = g_utils.takenull;
	if(!g_utils.takenull)
		return ;
}
