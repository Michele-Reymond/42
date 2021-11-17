/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:08:15 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/17 17:14:20 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			write_argument(str[i + 1]);
		write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
}

printf("coucou %d les copains", i);

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