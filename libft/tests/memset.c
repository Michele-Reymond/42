/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/12 11:03:47 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_memset.c"

int main()
{
	char str[] = "Coucou";
	char str2[] = "Coucou";
	char lettre = 'L';
	int nbr = 4;

	memset(str, lettre, nbr);
	printf("------\nmemset: %s\n", str);	
	ft_memset(str2, lettre, nbr);
	printf("ft_memset: %s\n––––\n", str2);
	return (0);
}
