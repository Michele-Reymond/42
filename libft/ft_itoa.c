/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:03:52 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/01 10:23:11 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_count(int n)
{
	int	len;

	if (n >= -9 && n <= -1)
		len = 1;
	else
		len = 0;
	n = n / 10;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		last;
	char	*str;

	neg = 1;
	if (n < 0)
		neg = -1;
	last = n % 10 * neg;
	len = itoa_count(n);
	n = n / 10;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[--len] = last + 48;
	while (--len > -1)
	{
		str[len] = (n * neg) % 10 + 48;
		n /= 10;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

// Alloue (avec malloc(3)) et retourne une chaine de
// caractères représentant l’integer reçu en argument.
// Les nombres négatifs doivent être gérés.

// PARAMS
// #1. l’integer à convertir.

// RETURN
// La chaine de caractères représentant l’integer.
// NULL si l’allocation échoue.