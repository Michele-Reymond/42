/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:04:27 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/08 18:31:42 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*dst = "";
	size_t		lecture;
	size_t		len;
	int 		i;
	static int 	b = 0;

	i = 0;
	len = 0;
	lecture = 1;
	dst = ft_strtrim(buffer, "\n");
	if (lecture == 0 || (fd < 0 || fd >= 1000))
		return (NULL);
	// ici je creer dst jusqu'au \n ou la fin du fichier
	while (lecture != 0)
	{
		printf("%d - buffer : %s\n", b, buffer);
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n') != 0)
		{
			dst = ft_strjoin(dst, "\n");
			break ;
		}
		dst = ft_strjoin(dst, buffer);
	}
	dst = ft_strjoin(dst, "\0");
	printf("%d - dst : %s\n", b, dst);
	b++;
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

// read un caractere a la fois jusqu'au \n
// le concatener a chaque fois


