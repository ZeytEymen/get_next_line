/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:27:10 by ekarabud          #+#    #+#             */
/*   Updated: 2024/01/10 15:27:16 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    if ((char)c == '\0')
        return ((char *)&s[i]);
    return (NULL);
}


char *ft_strjoin(char *f_str, char *l_str)
{
    char *new;
    int location;
    int i;

    if (!f_str)
    {
        f_str = malloc(sizeof(char) * 1);
        if (!f_str)
            return (NULL);
        f_str[0] = '\0';
    }
    new = malloc(sizeof(char) * (ft_strlen(f_str) + ft_strlen(l_str) + 1));
    if (!new)
        return (NULL);
    location = 0;
    i = 0;
    while (f_str[i] != '\0')
    {
        new[location] = f_str[i];
        location++;
        i++;
    }
    i = 0;
    while (l_str[i] != '\0')
    {
        new[location] = l_str[i];
        location++;
        i++;
    }
    new[location] = '\0';
    free(f_str);
    return new;
}