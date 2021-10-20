/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:54:46 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/20 11:03:50 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*str;
	unsigned char	lettre;

	lettre = c;
	i = 0;
	str = s;
	if (n == 0)
		return (NULL);
	while (str && i < n)
	{
		if (*str == lettre)
			return ((void *) str);
		str++;
		i++;
	}
	if (*str == lettre)
		return ((void *) str);
	return (NULL);
}
