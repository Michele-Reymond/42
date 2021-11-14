/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:20 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/14 18:30:00 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	lettre;
	char	*str;

	if (s == NULL)
		return (NULL);
	lettre = c;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == lettre)
			return (str);
		str++;
	}
	if (*str == lettre)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

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
		dst[j++] = str[i++];
	dst[j] = '\0';
	free(str);
	return (dst);
}