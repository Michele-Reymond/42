/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:04:27 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/09 16:52:22 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*befor_line_break(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\n';
	return (dst);
}

char	*after_line_break(char *str, int size)
{
	char	*dst;
	int		i;
	int		tmp;

	i = 0;
	tmp = size;
	while (str[size] != '\n')
	{
		i++;
		size--;
	}
	dst = malloc(sizeof(char) * i);
	size++;
	i = 0;
	while (size <= tmp)
	{
		dst[i] = str[size];
		size++;
		i++;
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*dst;
	char		*tmp;
	size_t		lecture;
	int			i;
	// size_t		len;

	i = 0;
	lecture = 1;
	tmp = after_line_break(buffer, BUFFER_SIZE);
	dst = tmp;
	if (lecture == 0 || (fd < 0 || fd >= 1000))
		return (NULL);
	while (lecture != 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n') != 0)
		{
			tmp = befor_line_break(buffer);
			dst = ft_strjoin(dst, tmp);
			break ;
		}
		if (lecture != 0)
			dst = ft_strjoin(dst, buffer);
	}
	free(tmp);
	dst = ft_strjoin(dst, "\0");
	printf("%s", dst);
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

// si 2 \n a la suite??