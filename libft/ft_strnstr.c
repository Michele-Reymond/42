/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:03:05 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/19 18:14:46 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*first;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (needle[i] == haystack[i] && needle[i] != '\0' && i < len)
		i++;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (needle[j] != haystack[i] && haystack[i] != '\0')
		i++;
	first = (char *)&haystack[i];
	while (needle[j] == haystack[i] && i < len - 1)
	{
		j++;
		i++;
	}
	if (needle[j - 1] == haystack[i - 1] && haystack[i] != '\0')
		return (first);
	return (NULL);
}

// needle : blabla
// haystack : coucoublabla	

// les
// 01234

// A
// 01

// si les 2 strings sont idem il faut faire -1 sinon il faut faire 0

// ne marche pas avec:
// char hay[] = "abFbFFcd";
// char need[] = "FF";