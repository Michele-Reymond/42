/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:20 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/10 17:10:48 by mreymond         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < (n - 1)
		&& str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (len < 0)
		return ((char *)haystack - 1);
	while (haystack[i] != '\0' && ((i < len - 1) || ft_strlen(needle) == 1)
		&& i <= (ft_strlen(haystack) - ft_strlen(needle)) && len > 0)
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			k = i - 1;
			while (needle[j] == haystack[++k] && needle[j] != '\0')
				j++;
			if (needle[j] == '\0' && k <= len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
