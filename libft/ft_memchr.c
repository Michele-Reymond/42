/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:54:46 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/18 15:04:25 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	const char		*str;

	i = 0;
	str = s;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == c)
			return ((void *) &str[i]);
		i++;
	}
	if (str[i] == c)
		return ((void *) &str[i]);
	return (NULL);
}
