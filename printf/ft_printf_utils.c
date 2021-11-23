/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:01 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/23 17:44:25 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	char	ptr[12];

	i = 0;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	while (n > 0)
	{
		ptr[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	while (--i > -1)
		write(1, &ptr[i], 1);
	return(3);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (0);
	while (s[++i] != '\0')
		write(1, &s[i], 1);
	return (i);
}

int	ft_puthexa(long int hexa)
{
	int	i;
	char str[100];
	char c;

	i = 0;
	while (hexa != 0)
	{
		c = hexa % 16;
		if (c >= 0 && c <= 9)
			str[i] = c + 48;
		if (c >= 10 && c <= 15)
			str[i] = c + 87;
		hexa = hexa / 16;
		i++;
	}
	i--;
	while (i > -1)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (i);
}


int	write_argument(char argument, va_list ap)
{
	int	count;

	count = 0;
	if (argument == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (argument == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (argument == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (argument == 'p')
		count = 1;
	else if (argument == 'x')
		count = ft_puthexa(va_arg(ap, unsigned int));
	return (count);
}

// La fonction retourne le nbr de caractères imprimés (variable static?)

// si argument == d
// > utiliser putnbr

// si argument == c
// > utiliser putchar

// si argument == s
// > utiliser putstring

// si argument == p
// > imprimer l'adresse du pointeur

// si argument == i
// > utiliser putnbr

// si argument == u
// > passer en positif
// > utiliser putnbr

// si argument == x
// > utiliser une fonction qui imprimer en Hexadecimale

// si argument == %
// > utiliser putchar de %
