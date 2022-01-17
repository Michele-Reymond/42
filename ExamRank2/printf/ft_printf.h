#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int ft_putstr(char *s);
int ft_putnbr(int n);
int hexa_count(unsigned int hexa);
int put_hexa(unsigned int hexa);
int write_argument(char lettre, va_list ap);
int ft_printf(const char *str, ...);

#endif
