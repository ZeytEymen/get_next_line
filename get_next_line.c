#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"


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


char    *read_line(int fd, char *str)
{
    char *temp;
    size_t readen_bytes;

    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
        return (0);
    while (!ft_strchr(temp,'\n'))
    {
        readen_bytes = read(fd,temp,BUFFER_SIZE);
        if (readen_bytes == -1)
        {
            free(temp);
            return (0);
        }
        temp[readen_bytes] = '\0';
        str = ft_strjoin(str,temp);
    }
    free(temp);
    
    return (str);
}

char	*get_next_line(int fd)
{
    return (0);
}

int main()
{
    char *str;
    int fd = open("metin.txt", O_RDONLY);
    read_line(fd,str);
    printf("%s",str);
    // int fd = open("metin.txt", O_RDONLY);
    // char str[100];
    // size_t readenBytes = read(fd,str,100);
    // printf("%s\n",str);
    // readenBytes = read(fd,str,100);
    // printf("%s\n",str);
    // readenBytes = read(fd,str,100);
    // printf("%s",str);
    // printf("\n%zu",readenBytes);

}