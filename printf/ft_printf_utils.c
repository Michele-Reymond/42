/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:01 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/24 18:41:57 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	char	ptr[12];
	int		count;

	i = 0;
	count = 0;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		count++;
		write(1, "0", 1);
	}
	if (n < 0)
	{
		count++;
		n = -n;
		write(1, "-", 1);
	}
	while (n > 0)
	{
		ptr[i] = n % 10 + 48;
		n /= 10;
		count++;
		i++;
	}
	while (--i > -1)
		write(1, &ptr[i], 1);
	return (count);
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
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[++i] != '\0')
		write(1, &s[i], 1);
	return (i);
}

int	ft_puthexa(size_t hexa, char lettre)
{
	int		i;
	char	str[100];
	char	c;
	int		count;

	i = 0;
	count = 0;
	while (hexa != 0)
	{
		c = hexa % 16;
		if (c >= 0 && c <= 9)
			str[i] = c + 48;
		if (c >= 10 && c <= 15 && (lettre == 'x' || lettre == 'p'))
			str[i] = c + 'a' - 10;
		if (c >= 10 && lettre == 'X')
			str[i] = c + 'A' - 10;
		hexa = hexa / 16;
		i++;
		count++;
	}
	i--;
	if (lettre == 'p')
	{
		count = count + 2;
		write(1, "0x", 2);
	}
	while (i > -1)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (count);
}

int	ft_putunsigned(int s)
{
	unsigned int	u;
	char			ptr[10];
	int				i;
	int				count;

	i = 0;
	count = 0;
	u = s + UINT_MAX + 1;
	while (u > 0)
	{
		ptr[i] = u % 10 + 48;
		u /= 10;
		count++;
		i++;
	}
	while (--i > -1)
		write(1, &ptr[i], 1);
	return (count);
}

int	write_argument(char argument, va_list ap)
{
	int	count;

	count = 0;
	if (argument == 'd' || argument == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (argument == 'u')
		count = ft_putunsigned(va_arg(ap, int));
	else if (argument == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (argument == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (argument == 'p')
		count = ft_puthexa(va_arg(ap, size_t), 'p');
	else if (argument == 'x')
		count = ft_puthexa(va_arg(ap, size_t), 'x');
	else if (argument == 'X')
		count = ft_puthexa(va_arg(ap, size_t), 'X');
	else if (argument == '%')
	{
		count = 1;
		write(1, "%", 1);
	}
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
