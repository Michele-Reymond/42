/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:33:37 by mreymond          #+#    #+#             */
/*   Updated: 2022/01/14 15:59:57 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *s, char lettre)
{
	if (s == NULL)
		return (NULL);
	while (s)
	{
		if (*s == lettre)
			return (s);
		s++;
	}
	if (*s == lettre)
		return (s);
	return (NULL);
}

char *ft_strjoin(char *str1, char *str2)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	j = ft_strlen(str1) + ft_strlen(str2);
	joined = (char *)malloc(sizeof(char) * j + 1);
	if (joined == NULL)
		return (NULL);
	j = 0;
	while (str1[i] != '\0')
	{
		joined[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		joined[i] = str2[j];
		j++;
		i++;
	}
	free(str1);
	joined[i] = '\0';
	return (joined);
}

char *clean_end_of_line(char *str)
{
	char *cleaned;
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	cleaned = (char *)malloc(sizeof(char) * i + 1);
	if (cleaned == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		cleaned[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		cleaned[i] = str[i];
		i++;
	}
	cleaned[i] = '\0';
	return (cleaned);
}

char *clean_start_of_line(char *str)
{
	char *cleaned;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	cleaned = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (cleaned == NULL)
		return (NULL);
	i++;
	while (str[i] != '\0')
	{
		cleaned[j] = str[i];
		i++;
		j++;
	}
	cleaned[j] = '\0';
	free(str);
	return (cleaned);
}

char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char *line;
	char		*returned_line;
	int			lecture;

	lecture = 1;
	if (fd < 0  || BUFFER_SIZE <= 0)
		return (NULL);
	while (lecture != 0 && ft_strchr(line, '\n') == NULL)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture == -1)
			return (NULL);
		buffer[lecture] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (line == NULL)
		return (NULL);
	returned_line = clean_end_of_line(line);
	line = clean_start_of_line(line);
	return (returned_line);
}

/*int main()
{
	int fd;
	char *line;
	int d;

	d = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line %d : %s", d, line);
	line = get_next_line(fd);
	d++;
	printf("line %d : %s", d, line);
}
*/



