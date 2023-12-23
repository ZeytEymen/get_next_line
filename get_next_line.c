#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <strings.h>


size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	bzero(buffer, count * size);
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	location;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	location = 0;
	while (s1[i])
	{
		new[location] = s1[i];
		i++;
		location++;
	}
	i = 0;
	while (s2[i])
	{
		new[location] = s2[i];
		i++;
		location++;
	}
	new[location] = '\0';
	return (new);
}


char    *ft_read_line(int fd, char *str)
{
    char 	*temp;
    size_t 	readen_bytes;

	readen_bytes = 1;
	if (str == 0)	
		str = ft_calloc(1,sizeof(char));
    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
        return (0);
    while (readen_bytes > 0)
    {
        readen_bytes = read(fd,temp,BUFFER_SIZE);
        if (readen_bytes == -1)
        {
            free(temp);
            return (0);
        }
        temp[readen_bytes] = '\0';
		str = ft_strjoin(str,temp);
		if (ft_strchr(temp,'\n'))
			break;
    }
	free(temp);
    return (str);
}

char *ft_write_line(char *str)
{
	int i = 0;
	char *temp;
	char *temp2;
	temp = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i]= '\0';
	return (strdup(temp));
}

char	*get_next_line(int fd)
{
	static char *str;
	str = ft_read_line(fd,str);
    return (str);
}


int main()
{
    int fd = open("metin.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	system("leaks a.out");
}

