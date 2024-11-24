/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:20:46 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/23 06:26:53 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*stays(char *storage_buffer)
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

char	*store(char *reading_buffer, t_fd_storage *fd_array, int fd)
{
	char	*temp;

	temp = fd_array[fd].s_b;
	fd_array[fd].s_b = ft_strjoin(fd_array[fd].s_b, reading_buffer);
	free(temp);
	free(reading_buffer);
	if (!fd_array[fd].s_b)
		return (NULL);
	return (fd_array[fd].s_b);
}

char	*get_next_line(int fd)
{
	static t_fd_storage	fd_a[10240];
	char				*r_b;
	ssize_t				read_bytes;
	char				*printing_buffer;

	(1) && (r_b = NULL, read_bytes = 0);
	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	while (1)
	{
		r_b = allocate(r_b, &read_bytes, fd);
		if (!r_b)
			return (free(fd_a[fd].s_b), fd_a[fd].s_b = NULL, NULL);
		fd_a[fd].s_b = store(r_b, fd_a, fd);
		if (!fd_a[fd].s_b)
			return (NULL);
		if (count_newlines(fd_a[fd].s_b) > 0 || read_bytes == 0)
		{
			printing_buffer = process_text(fd_a[fd].s_b);
			fd_a[fd].s_b = stays(fd_a[fd].s_b);
			if (read_bytes == 0 && !fd_a[fd].s_b)
				(1) && (free(fd_a[fd].s_b), fd_a[fd].s_b = NULL);
			return (printing_buffer);
		}
	}
}
