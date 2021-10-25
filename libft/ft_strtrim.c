/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:40:15 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/25 15:05:08 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		start;
	int		end;
	int		len;

	i = -1;
	start = 0;
	while (set[++i] != '\0')
	{
		while (set[i] == s1[start])
			start++;
	}
	i = ft_strlen(set) + 1;
	end = ft_strlen(s1);
	while (--i >= 0)
	{
		while (set[i] == s1[end])
			end--;
	}
	len = end - start + 1;
	str = ft_substr(s1, start, len);
	return (str);
}

// Alloue (avec malloc(3)) et retourne une copie de la chaine ’s1’, 
// sans les caractères spécifiés dans ’set’ au début et à la fin 
// de la chaine decaractères.

// PARAM 
// #1. La chaine de caractères à trimmer.
// #2. Le set de reference de caractères à trimmer.

// RETURN
// La chaine de caractères trimmée. NULL sil’allocation échoue