/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:18:37 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/22 23:21:24 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*what_stays(char *storage_buffer);
char	*process_text(char *storage_buffer);
char	*allocate(char *reading_buffer, ssize_t *read_bytes, int fd);
char	*store(char *reading_buffer, char *storage_buffer);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*concat(char *dest, char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		count_newlines(char *reading_buffer);

#endif
