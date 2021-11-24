/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:13:12 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/24 16:46:06 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	write_argument(char argument, va_list ap);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthexa(size_t hexa, char lettre);
int	ft_putunsigned(int s);

#endif