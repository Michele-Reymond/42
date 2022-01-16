#include "ft_printf.h"

int ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (0);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr(int n)
{
	
}

int write_argument(char lettre, va_list ap)
{
	int count;

	count = 0;
	if (lettre == 's')
		count = ft_putstr(va_arg(ap, char*));
	else if (lettre == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (lettre == 'x')
		count = ft_puthexa(va_arg(ap, unsigned int));
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
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else 
		{
			count = count + write_argument(str[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
