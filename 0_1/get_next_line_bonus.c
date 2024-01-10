/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:26:18 by ekarabud          #+#    #+#             */
/*   Updated: 2024/01/10 15:52:01 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *ft_read_line(int fd, char *str)
{
    char    *temp;
    int     readen_bytes;

    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
        return (NULL);
    readen_bytes = 1;
    while (!ft_strchr(str, '\n') && readen_bytes != 0)
    {
        readen_bytes = read(fd,temp,BUFFER_SIZE);
        if (readen_bytes == -1)
        {
            free(temp);
            free(str);
            return(NULL);
        }
        temp[readen_bytes] = '\0';
        str = ft_strjoin(str,temp);
    }
    free(temp);
    return (str);
}


char    *ft_line(char *str)
{
    char *new_line;
    int nl_i;

    nl_i = 0;
    if (!str[nl_i])
        return (NULL);
    while (str[nl_i] != '\0' && str[nl_i] != '\n')
        nl_i++;
    new_line = malloc(sizeof(char) * (nl_i + 2));
    if (!new_line)
        return (NULL);
    nl_i = 0;
    while (str[nl_i] != '\0' && str[nl_i] != '\n')
    {
        new_line[nl_i] = str[nl_i];
        nl_i++;
    }
    if (str[nl_i] == '\n')
    {
        new_line[nl_i] = str[nl_i];
        nl_i++;
    }
    new_line[nl_i] = '\0';
    return (new_line);
}

char    *ft_next_line(char  *str)
{
    char    *next_line;
    int     nl_i;
    int     i;

    if (!str)
        return (NULL);
    nl_i = 0;
    while (str[nl_i] != '\0' && str[nl_i] != '\n')
        nl_i++;
    if (!str[nl_i])
    {
        free(str);
        return (NULL);
    }
    next_line = malloc(sizeof(char) * ((ft_strlen(str) - nl_i) + 1));
    if (!next_line)
        return (NULL);
    i = 0;
    nl_i++;
    while (str[nl_i] != '\0')
    {
        next_line[i] = str[nl_i];
        i++;
        nl_i++;
    }
    next_line[i] = '\0';
    free(str);
    return (next_line);
}

char	*get_next_line(int fd)
{
    static char *str[10240];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    
    str[fd] = ft_read_line(fd,str[fd]);
    if (!str[fd])
        return (NULL);
    line = ft_line(str[fd]);
    str[fd] = ft_next_line(str[fd]);
    return (line);
}

