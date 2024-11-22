/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:57:18 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/22 05:17:49 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_newlines(char *storage_buffer, size_t *old_len)
{
	size_t	len;
	char	*sub;

	len = 0;
	if (!storage_buffer || *old_len >= strlen(storage_buffer))
	{
		return (NULL);
	}
	while (storage_buffer[*old_len + len] != '\n' && storage_buffer[*old_len
			+ len] != '\0')
		len++;
	sub = ft_substr(storage_buffer, *old_len, len + 1);
	*old_len += len + 1;
	return (sub);
}

int	count_new_line(char *arr, int *len)
{
	int	count;

	count = 0;
	while (arr[*len])
	{
		if (arr[*len] == '\n')
			count++;
		*len += 1;
	}
	return (count);
}

char	*join_it(char *storage_buffer, char *reading_buffer)
{
	char	*temp;

	temp = storage_buffer;
	storage_buffer = ft_strjoin(storage_buffer, reading_buffer);
	free(temp);
	free(reading_buffer);
	return (storage_buffer);
}

char	*read_allocate(char *reading_buffer, char *printing_buffer, int fd)
{
	static char		*storage_buffer;
	static int		len;
	static size_t	old_len;
	ssize_t			read_bytes;

	while (1)
	{
		reading_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		read_bytes = read(fd, reading_buffer, BUFFER_SIZE);
		reading_buffer = invalid_read(reading_buffer, storage_buffer,
				read_bytes);
		if (!reading_buffer)
			return (NULL);
		storage_buffer = join_it(storage_buffer, reading_buffer);
		if (count_new_line(storage_buffer, &len) > 0 || read_bytes == 0)
		{
			printing_buffer = check_newlines(storage_buffer, &old_len);
			if (!printing_buffer)
				return (free(storage_buffer), storage_buffer = NULL, len = 0,
					old_len = 0, NULL);
			break ;
		}
	}
	return (printing_buffer);
}

char	*get_next_line(int fd)
{
	static char	*reading_buffer;
	static char	*printing_buffer;

	if (!reading_buffer)
	{
		printing_buffer = read_allocate(reading_buffer, printing_buffer, fd);
		if (!printing_buffer)
		{
			free(printing_buffer);
			printing_buffer = NULL;
			return (NULL);
		}
	}
	return (printing_buffer);
}
