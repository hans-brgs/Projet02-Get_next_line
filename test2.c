#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 7



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	len_str_join;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	n = 0;
	len_str_join = strlen(s1) + strlen(s2);
	str_join = calloc(len_str_join + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	while (*s1)
	{
		str_join[n] = *s1;
		s1++;
		n++;
	}
	while (*s2)
	{
		str_join[n] = *s2;
		s2++;
		n++;
	}
	return (str_join);
}

char *streplace(char *str, char c)
{
	char *ptr;
	ptr = str;
	while(*ptr)
	{
		if(*ptr == c)
		{
			*ptr = 0;
			return(str);
		}
		ptr ++;
	}
	return(NULL);
}

char *ft_realloc(char **ptr)
{
	char *newptr;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (**ptr != '\n')
		ptr++;
	ptr++;
	while(**ptr != '\0')
	{
		ptr++;
		i++;
	}
	newptr = calloc(i + 1, sizeof(*ptr)); 
	if(!newptr)
		return (NULL);
	memcpy(newptr, ptr, i);
	free(*ptr);

	return (newptr);
}

// char *read_line(int fd, char* buf, char *str)
// {
// 	int ret;
// 	char *line;

	
// 	return (line);
// }

char *get_next_line(int fd)
{
	static char *buf;
	char *str;
	char *line;
	int ret;

	str = "\0";
	if (!buf)
		buf = calloc((BUFFER_SIZE + 1), sizeof(char));
	else
		str = ft_strjoin(str, buf);
	// line = read_line(fd, buf, str);
	while (strchr(buf,'\n') == NULL)
	{	
		ret = read(fd, (char *)buf, BUFFER_SIZE);
		if (ret < BUFFER_SIZE)
			break;
		str = ft_strjoin(str, buf);
	}
	if (memchr(buf,'\n',BUFFER_SIZE))
	{
		line = streplace(str,'\n');
		buf = ft_realloc(&buf);
	}
	else
		line = str;
	return(line);
}

int main ()
{
	int fd;
	char *s;
	
	fd = open("text.txt", O_RDONLY, 0);
	
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%s",s);
		free(s);
	}
	
	
}