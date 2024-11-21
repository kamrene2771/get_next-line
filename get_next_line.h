/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:30 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/21 23:10:20 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
char *read_allocate(char *reading_buffer,char *printing_buffer,int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*concat(char *dest, char *s);
char	*ft_strjoin(char *s1, char *s2);
char *check_newlines(char *storage_buffer,size_t *old_len);

#endif