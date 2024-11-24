/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:11:17 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/23 09:28:53 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*what_stays(char *storage_buffer)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (storage_buffer[i] != '\n' && storage_buffer[i] != '\0')
	{
		i++;
	}
	if (storage_buffer[i] == '\0')
	{
		free(storage_buffer);
		return (NULL);
	}
	i++;
	temp = ft_substr(storage_buffer, i, ft_strlen(storage_buffer) - i);
	free(storage_buffer);
	return (temp);
}

char	*process_text(char *storage_buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (storage_buffer[i] != '\n' && storage_buffer[i] != '\0')
	{
		i++;
	}
	if (storage_buffer[i] == '\n')
		i++;
	line = ft_substr(storage_buffer, 0, i);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*allocate(char *reading_buffer, ssize_t *read_bytes, int fd)
{
	reading_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reading_buffer)
		return (NULL);
	*read_bytes = read(fd, reading_buffer, BUFFER_SIZE);
	if (*read_bytes < 0)
	{
		free(reading_buffer);
		reading_buffer = NULL;
		return (NULL);
	}
	reading_buffer[*read_bytes] = '\0';
	return (reading_buffer);
}

char	*store(char *reading_buffer, char *storage_buffer)
{
	char	*temp;

	temp = storage_buffer;
	storage_buffer = ft_strjoin(storage_buffer, reading_buffer);
	free(temp);
	free(reading_buffer);
	if (!storage_buffer)
		return (NULL);
	return (storage_buffer);
}

char	*get_next_line(int fd)
{
	static char	*storage_buffer;
	char		*printing_buffer;
	char		*reading_buffer;
	ssize_t		read_bytes;

	(1) && (reading_buffer = NULL, read_bytes = 0);
	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	while (1)
	{
		reading_buffer = allocate(reading_buffer, &read_bytes, fd);
		if (!reading_buffer)
			return (free(storage_buffer), storage_buffer = NULL, NULL);
		storage_buffer = store(reading_buffer, storage_buffer);
		if (!storage_buffer)
			return (NULL);
		if (count_newlines(storage_buffer) > 0 || read_bytes == 0)
		{
			printing_buffer = process_text(storage_buffer);
			if (!printing_buffer)
				return (free(storage_buffer), storage_buffer = NULL, NULL);
			storage_buffer = what_stays(storage_buffer);
			return (printing_buffer);
		}
	}
}
