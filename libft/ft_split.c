/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:07:52 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/27 17:46:26 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 
#include <stdlib.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**strtab;
	char	*str;
	char	*str2;
	int		i;
	int		j;
	int		y;
	int		temp;
	int		sep;

	i = 0;
	y = 0;
	sep = 0;
	str = ft_strtrim(s, &c);
	if (ft_strtrim(s, &c) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			sep++;
		i++;
	}
	i = 0;
	strtab = (char **)malloc(sizeof(char *) * (sep + 2));
	if (!strtab)
		return (NULL);
	while (str[i] != '\0')
	{
		str2 = &str[i];
		j = 0;
		while (str2[j] == c)
			j++;
		temp = j;
		while (str2[j] != c && j <= (int)ft_strlen(str2))
		{
			j++;
			i++;
		}
		strtab[y] = (char *)malloc(sizeof(char) * (j - temp) + 1);
		if (!strtab[y])
			return (NULL);
		ft_strlcpy(strtab[y], &str2[temp], j + 1);
		y++;
		i++;
	}
	strtab[y] = NULL;
	return (strtab);
}

// LLL-Coucou-les-poilus-LLL

// Alloue (avec malloc(3)) et retourne un tableau de chaines 
// de caracteres obtenu en séparant ’s’ à l’aide du caractère ’c’, 
// utilisé comme délimiteur. Le tableau doit être terminé par NULL.

// PARAM 
// #1. La chaine de caractères à découper.
// #2. Le caractère délimitant.

// RETURN
// Le tableau de nouvelles chaines de caractères,résultant du découpage. 
// NULL si l’allocation échoue.

// PSEUDO CODE
// verifier s'il y a un separateur au debut
// compter le nombre de separateur
// calculer la taille du premier tronçon jusqu'au separateur
// allouer la memoire et copier ce tronçon sans un tableau
// passer au prochain tableau
