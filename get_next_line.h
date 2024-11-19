/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:30 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/19 05:05:10 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

struct		s_utils
{
	char	*ptr;   // buffer to read data
	ssize_t	readbytes; // bytes read from file
	char	*nullter; //new buffer to add \0
	char 	*toprint;
	size_t	i; // trackes bytes 
	size_t	j; // new line count
}	g_utils;

char	*copywithmod(char *src ,ssize_t readbytes);
int		count_nl(char *ptr,ssize_t readbytes);
char		*get_next_line(int fd);
void	read_alloc(int fd);
size_t	ft_strlen(const char *str);
char	*concat(size_t len, char *dest, char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif