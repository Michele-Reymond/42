/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:39:08 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/18 18:30:47 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] != '\0' && j < (dstsize - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	while (src[i] != '\0')
		i++;
	dst[j] = '\0';
	if (dstsize > i)
		return (i + dstsize);
	else
		return (i);
}
