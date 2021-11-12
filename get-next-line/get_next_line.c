/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:04:27 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/12 16:57:53 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_end_of_line(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * i + 2);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*clean_start_of_line(char *str)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (dst == NULL)
		return (NULL);
	i++;
	while (str[i])
	{
		dst[j] = str[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	free(str);
	return (dst);
}

char	*get_a_line(int fd, char *str)
{
	char		*buff;
	int			lecture;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	lecture = 1;
	while (lecture != 0 && !ft_strchr(str, '\n'))
	{
		lecture = read(fd, buff, BUFFER_SIZE);
		if (lecture == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[lecture] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char 		*tmpline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = get_a_line(fd, line);
	if (line == NULL)
		return (NULL);
	tmpline = clean_end_of_line(line);
	line = clean_start_of_line(line);
	return (tmpline);
}

// Write a function which returns a line read from a file descriptor

// PARAM
// File descriptor to read from

// RETURN
// Read line:  correct behavior
// NULL: nothing else to read or an error occurred

// FUNCTIONS
// read, malloc, free