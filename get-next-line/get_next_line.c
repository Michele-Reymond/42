/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:04:27 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/07 18:47:10 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE];
	char	*dst;
	size_t	a;
	int		len;
	int		i;

	i = 0;
	len = 0;
	a = read(fd, str, BUFFER_SIZE);
	if (a == 0)
		return (NULL);
	while (str[len] != '\n' && len < BUFFER_SIZE)
		len++;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	while (str[i] != '\n' && i < BUFFER_SIZE)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\n';
	dst[++i] = '\0';
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
