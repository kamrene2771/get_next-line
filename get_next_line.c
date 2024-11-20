/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:39:36 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/20 05:39:47 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

	if (fd < 0)
		return (NULL);
	if (g_utils.takenull == NULL)
	{
		read_alloc(fd);	
		while (g_utils.readbytes > 0 && g_utils.takenull)
			read_alloc(fd);
		if (!g_utils.takenull)
			return NULL;
		g_utils.takenull = NULL;
	}
	return g_utils.toprint;
}
int main(){
    char *str;
    int fd = open("file.txt",O_RDONLY);
    
	str = get_next_line(fd);
	printf("%s",str);
	close(fd);
	str = get_next_line(fd);
	printf("%s",str);
	// printf("\n");
	// str = get_next_line(fd);
	// printf("%s",str);
	// str = get_next_line(fd);
	// printf("%s",str);
	// printf("\n");
	// str = get_next_line(fd2);
	// printf("%s",str);
	// str = get_next_line(fd2);
	// printf("%s",str);
	// printf("\n");
	// str = get_next_line(fd1);
	// printf("%s",str);
	// str = get_next_line(fd1);
	// printf("%s",str);
	
	 //close(fd);
	// str = get_next_line(fd);
	// printf("%s",str);
	
	// while((str = get_next_line(fd)) != NULL){
    //     printf("%s",str);
    // }
}