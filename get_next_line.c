/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:36 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/19 05:29:11 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

	if (fd < 0)
		return (NULL);
	if (g_utils.toprint == NULL)
	{
		read_alloc(fd);
		while (g_utils.readbytes > 0)
			read_alloc(fd);
		return (g_utils.toprint);
	}
	return NULL;
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
	// str = get_next_line(fd);
	// printf("%s",str);
	// str = get_next_line(fd);
	// printf("%s",str);
	 close(fd);
	// str = get_next_line(fd);
	// printf("%s",str);
	
	// while((str = get_next_line(fd)) != NULL){
    //     printf("%s",str);
    // }
}