/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:06:13 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/07 18:41:26 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 7

char *get_line (char *buf, char *line)
{
	if(strchr(buf, '\n'))
		substr()
}

char *get_next_line(int fd)
{
	static char *buf;
	char *line;
	int ret;
	
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ret = read(fd, buf, BUFFER_SIZE);
	while (!strchr(buf, '\n') && ret != 0)
	{
		ret = read(fd,buf,BUFFER_SIZE);
		get_line(buf, line);
	}
	return (buf);
}

int main ()
{
	int fd;
	char *s;
	
	fd = open("text.txt", O_RDONLY, 0);
	
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%s",s);
		// free(s);
	}
	
	
}