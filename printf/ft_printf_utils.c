/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:01 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/17 17:30:14 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	itoa_count(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	neg = 1;
	if (n < 0)
		neg = -1;
	len = itoa_count(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (--len > -1)
	{
		str[len] = (n % 10) * neg + 48;
		n /= 10;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

int	write_argument(char argument)
{
	int	count;

	count = 0;
	if (argument == 'd')
	{
		ft_itoa(argument);
		count = count + itoa_count(argument);
	}
	return (count);
}

// La fonction retourne le nbr de caractères imprimés (variable static?)

// si argument == d
// > utiliser itoa

// si argument == c
// > utiliser putchar

// si argument == s
// > utiliser putstring

// si argument == p
// > imprimer l'adresse du pointeur

// si argument == i
// > utiliser itoa

// si argument == u
// > passer en positif
// > utiliser itoa

// si argument == x
// > utiliser une fonction qui imprimer en Hexadecimale

// si argument == %
// > utiliser putchar de %
