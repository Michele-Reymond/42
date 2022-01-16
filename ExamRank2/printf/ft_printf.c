#include "ft_printf.h"

int ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
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
  int i;
  int count;
  char str[12];
  int tmp;

  count = 0;
  i = 0;
  tmp = n;
  if (n == INT_MIN)
  {
    write(1, "-2147483648", 11);
    return(11);
  }
  if (n == 0)
  {
    write(1, "0", 1);
    count = 1;
  }
  if (n < 0)
  {
    count = 1;
    n = -n;
    write(1, "-", 1);
  }
  while (n > 0)
  {
    str[i] = n % 10 + 48;
    n /= 10;
    count++;
    i++;
  }
  i--;
  while (i >= 0)
  {
    write(1, &str[i], 1);
    i--;
  }
  return (count);
}

int hexa_count(unsigned int hexa)
{
  int count;

  count = 0;
  if (hexa == 0)
  {
    count = 1;
    write(1, "0", 1);
  }
  while (hexa != 0)
  {
    hexa = hexa / 16;
    count++;
  }
  return (count);
}

void hexa_write(int size, char *str)
{
  while (size >= 0)
  {
    write(1, &str[size], 1);
    size--;
  }
  free(str);
}

int put_hexa(unsigned int hexa)
{
  int count;
  char *str;
  char c;
  int i;

  i = 0;
  count = hexa_count(hexa);
  str = (char *)malloc(sizeof(char) * count);
  if (str == NULL)
    return (0);
  while (hexa != 0)
  {
    c = hexa % 16;
    if (c >= 0 && c <= 9)
      str[i] = c + 48;
    else 
      str[i] = c + 'a' - 10;
    hexa = hexa / 16;
    i++;    
  }
  hexa_write(i - 1, str);
  return (count);
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
		count = put_hexa(va_arg(ap, unsigned int));
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
      i++;
			count = count + write_argument(str[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
