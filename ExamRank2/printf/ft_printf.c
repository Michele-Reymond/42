#include "ft_printf.h"


int ft_putstr(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr(int nbr)
{
	int i;
	int count;
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
		write(1, &str[i], 1);
		i--;
	}
	return (count);
}

int put_hexa(unsigned int hex)
{
	char c;
	int i;
	int count;
	char *str;
	unsigned int tmp;

	i = 0;
	count = 0;
	tmp = hex;
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (tmp > 0)
	{
		tmp = tmp / 16;
		count ++;
	}
	str = malloc(count);
	if (str == NULL)
		return (0);
	while (hex > 0)
	{
		c = hex % 16;
		if (c >= 0 && c <= 9)
			str[i] = c + 48;
		else 
			str[i] = c + 'a' - 10;
		hex = hex / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	free(str);
	str = NULL;
	return (count);
}

int write_argument(char lettre, va_list ap)
{
	int count;

	if (lettre == 's')
		count = ft_putstr(va_arg(ap, char *));
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
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else {
			i++;
			count = count + write_argument(str[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (count)
;}


















// int ft_putstr(char *str)
	// ________3 STEPS_________
	// 1. si str est NULL write (null) et return 6
	// 2. itérer sur str et write toutes les lettres de str
	// 3. return (i);

// int ft_putnbr(int nbr)
	// ________7 STEPS_________
	// 1. INT_MIN
	// 2. si nbr vaut 0
	// 3. si nbr est négatif
	// 4. itérer tant que nbr est plus grand que zéro
	// 	4.1 modulo 10 sur nbr, convertir en char et mettre dans str[i]
	// 	4.2 diviser nbr par 10
	// 	4.3 count ++;
	// 5. i--
	// 6. imprimer str[i] tant qui i >= 0
	// 7. return count


// int put_hexa(unsigned int hex)
	// ________9 STEPS_________
	// 1. tmp = hex
	// 2. si hex vaut zéro write 0 et return 1
	// 3. tant que hex est plus grand que zéro diviser par 16 et count ++
	// 4. malloc de count sur str
	// 5. tant que tmp est plus grand que zéro itérer
	// 	5.1 c = tmp % 16
	// 	5.2 si c est compri entre 0 et 9 concertir en char
	// 	5.3 sinon faire + a - 10
	// 	5.4 diviser tmp par 16
	// 6. i--;
	// 7. tant que i >= 0 imprimer str[i]
	// 8. free str
	// 9. return count

// int write_argument(char lettre, va_list ap)
	// ________5 STEPS_________
	// 1. si lettre == s
	// 2. sinon si lettre == d
	// 3. sinon si lettre == x
	// 4. sinon count vaut 0
	// 5. return count

// int ft_printf(const char *str, ...)
	// ________4 STEPS_________
	// 1. va_start
	// 2. itérer sur str
	// 	2.1 si on ne tombe pas sur un % write str[i] et count ++
	// 	2.2 sinon i++ et count vaut count + write_arguments
	// 3. va_end
	// 4. return count


// void ft_putchar(char lettre)
// {
// 	write(1, &lettre, 1);
// }

// int ft_putstr(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (str == NULL)
// 	{
// 		write(1, "(null)", 6);
// 		return (6);
// 	}
// 	while (str[i] != '\0')
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// 	return (i);
// }

// int ft_putnbr(int nbr)
// {
// 	int count;
// 	int i;
// 	char str[12];

// 	i = 0;
// 	count = 0;
// 	if (nbr == INT_MIN)
// 	{
// 		write(1, "-2147483648", 11);
// 		return (11);
// 	}
// 	if (nbr == 0)
// 	{
// 		write(1, "0", 1);
// 		return (1);
// 	}
// 	if (nbr < 0)
// 	{
// 		nbr = -nbr;
// 		write(1, "-", 1);
// 		count++;
// 	}
// 	while (nbr > 0)
// 	{
// 		str[i] = nbr % 10 + 48;
// 		nbr = nbr / 10;
// 		i++;
// 		count++;
// 	}
// 	i--;
// 	while (i >= 0)
// 	{
// 		ft_putchar(str[i]);
// 		i--;
// 	}
// 	return (count);
// }

// int put_hexa(unsigned int hex)
// {
// 	unsigned int tmp;
// 	int i;
// 	int count;
// 	char c;
// 	char *str;

// 	i = 0;
// 	count = 0;
// 	tmp = hex;
// 	if (hex == 0)
// 	{
// 		write(1, "0", 1);
// 		return (1);
// 	}
// 	while (hex != 0)
// 	{
// 		hex = hex / 16;
// 		count++;
// 	}
// 	str = (char *)malloc(sizeof(char) * count);
// 	if (str == NULL)
// 		return (0);
// 	while (tmp != 0)
// 	{
// 		c = tmp % 16;
// 		if (c >= 0 && c <= 9)
// 			str[i] = c + 48;
// 		else
// 			str[i] = c + 'a' - 10;
// 		tmp = tmp / 16;
// 		i++;
// 	}
// 	i--;
// 	while (i >= 0)
// 	{
// 		ft_putchar(str[i]);
// 		i--;
// 	}
// 	free(str);
// 	return (count);
// }

// int write_argument(char lettre, va_list ap)
// {
// 	int count;

// 	if (lettre == 's')
// 		count = ft_putstr(va_arg(ap, char*));
// 	else if (lettre == 'd')
// 		count = ft_putnbr(va_arg(ap, int));
// 	else if (lettre == 'x')
// 		count = put_hexa(va_arg(ap, unsigned int));
// 	else 
// 		count = 0;
// 	return (count);
// }

// int ft_printf(const char *str, ...)
// {
// 	va_list ap;
// 	int i;
// 	int count;

// 	i = 0;
// 	count = 0;
// 	va_start(ap, str);
// 	while(str[i] != '\0')
// 	{
// 		if (str[i] != '%')
// 		{
// 			ft_putchar(str[i]);
// 			count++;
// 		}
// 		else
// 		{
// 			i++;
// 			count = count + write_arguments(str[i], ap);
// 		}
// 		i++;
// 	}
// 	va_end(ap);
// 	return (count);
// }
