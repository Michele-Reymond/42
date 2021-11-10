/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:04:27 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/10 17:41:45 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*end_of_line(char *str, int size)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] != '\n' && i < size)
		i++;
	while (str[i] == '\n' && i < size)
		i++;
	dst = malloc(sizeof(char) * i + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && i < size)
	{
		dst[i] = str[i];
		i++;
	}
	while (str[i] == '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*start_of_line(char *str, int size)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strchr(str, '\n') == 0)
		return (str);
	while (str[i] != '\n' && i < size)
		i++;
	dst = malloc(sizeof(char) * size - i + 1);
	if (dst == NULL)
		return (NULL);
	while (str[i] == '\n')
	{
		dst[j] = str[i];
		i++;
		j++;
	}
	while (i <= size)
	{
		dst[j] = str[i];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*dst = "";
	int			lecture;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lecture = read(fd, buffer, BUFFER_SIZE);
	if (lecture == -1)
		return (NULL);
	dst = start_of_line(buffer, BUFFER_SIZE);
	while (lecture != 0 && ft_strchr(buffer, '\n') == 0)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		dst = ft_strjoin(dst, buffer);
	}
	dst = ft_strjoin(dst, end_of_line(buffer, BUFFER_SIZE));
	printf("%s\n", dst);
	return (dst);
}

// Write a function which returns a line read from a file descriptor

// PARAM
// File descriptor to read from

// RETURN
// Read line:  correct behavior
// NULL: nothing else to read or an error occurred

// FUNCTIONS
// read, malloc, free