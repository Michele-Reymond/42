/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:20 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/09 16:35:19 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	lettre;
	char	*str;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	j;
	char	*str;
	size_t	len;

	i = -1;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	len = j + ft_strlen(s2) + 2;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len > size && start < size)
		len = size - (size_t)start + 1;
	if (start > size)
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start] != '\0' && start < size)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = str;
	i = 0;
	while (i < n && n != 0)
	{
		a[i] = '\0';
		i++;
	}
}

