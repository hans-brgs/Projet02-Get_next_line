/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:20:04 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/06 08:28:00 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define BUFFER_SIZE

char *get_next_line(int fd)
{
	static char *s;
	char buf[BUFFER_SIZE + 1];
	int ret;
	
	if (buf || fd)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		s = strjoin(s, buf);
		if (strcmp(s, '\n'))
			return (s);
		s = strdup();	
	}
	return (s);
}

int main ()
{
	int fd;
	
	fd = open("text.txt", O_RDONLY, 0)
}