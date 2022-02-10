/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:06:13 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/10 15:30:04 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = c;
		str++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_join;
	size_t	n;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	n = 0;
	j = 0;
	str_join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	while (s1[n])
	{
		str_join[n] = s1[n];
		n++;
	}
	while (s2[j])
		str_join[n++] = s2[j++];
	// str_join[n] = '\0';
	free(s1);
	return (str_join);
}

char	*get_line(char *str)
{
	size_t	n;
	char	*ptr;

	n = 0;
	if (!*str)
		return (NULL);
	while (str[n] && str[n] != '\n')
		n++;
	ptr = ft_calloc(n + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	n = 0;
	while (str[n] && str[n] != '\n')
	{
		ptr[n] = str[n];
		n++;
	}
	if (str[n] == '\n')
	{
		ptr[n] = str[n];
		n++;
	}
	// ptr[n] = '\0';
	return (ptr);
}

char	*keep_remains(char *str)
{
	size_t	n;
	size_t	j;
	char	*ptr;

	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	if (!str[n])
	{
		free (str);
		return (NULL);
	}
	n++;
	ptr = ft_calloc(ft_strlen(&str[n]) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (str[n] && str[n])
		ptr[j++] = str[n++];
	ptr[j] = '\0';
	free(str);
	return (ptr);
}

char	*read_file(int fd, char *str)
{
	char	*buf;
	int		is_end;

	is_end = 1;
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && is_end != 0)
	{
		is_end = read(fd, buf, BUFFER_SIZE);
		if (is_end == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[is_end] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = keep_remains(str);
	return (line);
}

int main ()
{
	int fd;
	char *s;
	int n;
	
	n = 0;
	s = NULL;
	fd = open("gnlTester/files/nl", O_RDONLY);
	while (n < 1)
	{
		s = get_next_line(fd);
		printf("%s",s);
		free(s);
	 	n++;
	}
}