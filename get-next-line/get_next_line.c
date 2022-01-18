/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:04:27 by mreymond          #+#    #+#             */
/*   Updated: 2022/01/18 14:12:27 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*return_line;
	char		buffer[BUFFER_SIZE + 1];
	int			lecture;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lecture = 1;
	while (lecture != 0 && !ft_strchr(line, '\n'))
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture == -1)
			return (NULL);
		buffer[lecture] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (line == NULL)
		return (NULL);
	return_line = clean_end_of_line(line);
	line = clean_start_of_line(line);
	return (return_line);
}

// Write a function which returns a line read from a file descriptor

// PARAM
// File descriptor to read from

// RETURN
// Read line:  correct behavior
// NULL: nothing else to read or an error occurred

// FUNCTIONS
// read, malloc, free
