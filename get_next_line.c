/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:36 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/19 04:32:54 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*dst;

	if (fd < 0)
		return (NULL);
	if (g_utils.i >= (g_utils.readbytes + g_utils.j))
		 g_utils.nullter = NULL;
	if (g_utils.nullter == NULL)
	{
		read_alloc(fd);
		if (g_utils.readbytes <= 0)
			return (NULL);
	}
	if(g_utils.nullter[0] == '\0')
		return NULL;
	dst = g_utils.nullter;
	while (*g_utils.nullter)
	{
		g_utils.nullter++;
		g_utils.i++;
	}
	g_utils.nullter++;
	g_utils.i++;
	return (dst);
}
int main(){
    char *str;
    int fd = open("file.txt",O_RDWR);
    // while((str = get_next_line(fd)) != NULL){
    //     printf("%s",str);
    // }
	str = get_next_line(fd);
	printf("%s",str);
	// str = get_next_line(fd);
	// printf("%s",str);
	 close(fd);
	// str = get_next_line(fd);
	// printf("%s",str);
	
	// while((str = get_next_line(fd)) != NULL){
    //     printf("%s",str);
    // }
}