#include "get_next_line.h"

char    *ft_read_line(int fd, char *str)
{
    char 	*temp;
	int 	readen_bytes;

	readen_bytes = 1;
	if (str == 0)
	{
		str = malloc(sizeof(char) * 1);
    	if (!str)
			return (NULL);
	}
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
        return (0);
    while (readen_bytes > 0)
    {
        readen_bytes = read(fd,temp,BUFFER_SIZE);
        if (readen_bytes == -1)
        {
            free(temp);
            return (NULL);
        }
        temp[readen_bytes] = '\0';
		str = ft_strjoin(str,temp);
		if (ft_strchr(str,'\n'))
			break;
    }
	free(temp);
    return (str);
}

char *ft_write_and_next_line(char *str,int method)
{
	if (str[0] == '\0')
		return (NULL);
	int line_index;
	char *line;
	char *next_line;
	int str_index;
	
	str_index = 0;
	line_index = ft_strchr(str,'\n') - str + 1;
	if (method == 0)
	{	
		next_line = ft_substr(str,line_index,ft_strlen(str) - line_index);
		free(str);
		return (next_line);
	}
	else if (method == 1)
	{
		line = ft_substr(str,0,line_index);
		return (line);
	}
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char *str;
	char 		*line;
	str = ft_read_line(fd,str);
	if (!str)
		return (0);
	line = ft_write_and_next_line(str, 1);
	str = ft_write_and_next_line(str, 0);
    return (line);
}