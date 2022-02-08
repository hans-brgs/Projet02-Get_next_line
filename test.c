#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 3


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

void *ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void *newptr;

	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}
	else if (!ptr)
	{
		return( malloc(new_size));
	}
	else if (new_size < original_size)
		return (ptr);
	
	newptr = malloc(sizeof(*ptr) * new_size); 
	if(!newptr)
		return (NULL);
	memcpy(newptr, ptr, original_size);
	free(ptr);

	return (newptr);
}

char *get_next_line(int fd)
{
	static char *s;
	char *buf;
	char *str;
	int ret;
	static int n;
	char *line;
	
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	str = malloc(sizeof(char));
	// if (buf || fd)
	// 	return (NULL);
	if ()
	while ((ret = read(fd, (char *)buf, BUFFER_SIZE)) > 0)
	{
		if (strchr(buf,'\n'))
		{
			line = streplace(s,'\n');
			while (*buf)
				buf++;
			return(s);	
		}
		str = ft_realloc(str, strlen(s) + 1, strlen(s) + BUFFER_SIZE + 1);
		s = strcat(s, buf);
		
			
	}
	return (line);
}

int main ()
{
	int fd;
	char *s;
	
	fd = open("text.txt", O_RDONLY, 0);
	
	while ((s = get_next_line(fd)) != NULL)
		printf("%s",s);
	
	
}