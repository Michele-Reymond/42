/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:01 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/25 17:38:04 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrwrite(int n)
{
	int		i;
	char	ptr[12];
	int		count;

	i = 0;
	count = 0;
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

int	ft_putnbr(int n)
{
	int	count;

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
	count = count + ft_putnbrwrite(n);
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

int	ft_hexwrite(size_t hexa, char lettre)
{
	int		i;
	char	str[10];
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
	while (--i > -1)
		write(1, &str[i], 1);
	return (count);
}

int	ft_puthexa(unsigned int hexa, char lettre)
{
	int		count;

	count = 0;
	if (hexa == 0)
	{
		count++;
		write(1, "0", 1);
	}
	count = count + ft_hexwrite(hexa, lettre);
	return (count);
}

int	ft_putadresse(size_t adresse)
{
	int		count;

	count = 2;
	write(1, "0x", 2);
	if (adresse == 0)
	{
		count++;
		write(1, "0", 1);
	}
	count = count + ft_hexwrite(adresse, 'p');
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
	if (u == 0)
	{
		write(1, "0", 1);
		count++;
	}
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
		count = ft_putadresse(va_arg(ap, size_t));
	else if (argument == 'x')
		count = ft_puthexa(va_arg(ap, unsigned int), 'x');
	else if (argument == 'X')
		count = ft_puthexa(va_arg(ap, unsigned int), 'X');
	else if (argument == '%')
	{
		count = 1;
		write(1, "%", 1);
	}
	return (count);
}

// La fonction retourne le nbr de caractères imprimés
