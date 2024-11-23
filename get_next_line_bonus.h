/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:20:50 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/23 01:18:25 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_fd_storage
{
	char	*s_b;
}			t_fd_storage;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*concat(char *dest, char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*process_text(char *storage_buffer);
char		*stays(char *storage_buffer);
int			count_newlines(char *reading_buffer);

#endif
