/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/26 16:46:18 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_strlen.c"
#include "../ft_itoa.c"

int	main()
{
	int i;
	i = 0;
	char *str = ft_itoa(-1234);

	printf("str: %s\n", str );

	free(str);
}	 

// 1. faire une fonction qui calcule la len
// 2. utiliser un temporaire pour directement 
// diviser l'int et que INTMAX soit OK