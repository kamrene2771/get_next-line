/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:14:14 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/22 22:14:53 by kamrene          ###   ########.fr       */
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
	dest = concat(dest, s2);
	*dest = '\0';
	return (cat);
}

int	count_newlines(char *reading_buffer)
{
	int	count;

	count = 0;
	while (*reading_buffer)
	{
		if (*reading_buffer == '\n')
			count++;
		reading_buffer++;
	}
	return (count);
}
