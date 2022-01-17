#include "ft_printf.h"

void ft_putchar(char lettre)
{
	write(1, &lettre, 1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int nbr)
{
	int count;
	int i;
	char str[12];

	i = 0;
	count = 0;
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i++;
		count++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
	return (count);
}

int put_hexa(unsigned int hex)
{
	unsigned int tmp;
	int i;
	int count;
	char c;
	char *str;

	i = 0;
	count = 0;
	tmp = hex;
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (hex != 0)
	{
		hex = hex / 16;
		count++;
	}
	str = (char *)malloc(sizeof(char) * count);
	if (str == NULL)
		return (0);
	while (tmp != 0)
	{
		c = tmp % 16;
		if (c >= 0 && c <= 9)
			str[i] = c + 48;
		else
			str[i] = c + 'a' - 10;
		tmp = tmp / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
	free(str);
	return (count);
}

int write_arguments(char lettre, va_list ap)
{
	int count;

	if (lettre == 's')
		count = ft_putstr(va_arg(ap, char*));
	else if (lettre == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (lettre == 'x')
		count = put_hexa(va_arg(ap, unsigned int));
	else 
		count = 0;
	return (count);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while(str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			count++;
		}
		else
		{
			i++;
			count = count + write_arguments(str[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
