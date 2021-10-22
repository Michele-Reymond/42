/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:03:05 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/22 15:36:07 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

size_t	ft_strlen(const char *str);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		size;
	int			j;
	int			k;

	i = 0;
	size = ft_strlen(haystack) - ft_strlen(needle);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && (i < len - 1
			|| ft_strlen(needle) == 1) && i <= size && len > 0)
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			k = i - 1;
			while (needle[j] == haystack[++k] && needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}		
		i++;
	}
	return (NULL);
}
