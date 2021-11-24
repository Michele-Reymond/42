/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:08:15 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/24 18:41:58 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

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

/**
 * @brief fonction qui fonctionne comme printf
 * @return int (nbr de charactères imprimés avant le \0)
 * arglist est un objet de type va_list (liste des arguments)
 */

//PSEUDO CODE
//  1. il faut iterer tant qu'on est pas a la fin de la string
//  2. si on tombe sur un % on check le caractere suivant pour 
//  le remplacer par ce qu-il faut
//  3. si c'est un d utiliser putnbr par exemple. 
//  4. sinon on utilise putchar et on compte le nbr de caracteres