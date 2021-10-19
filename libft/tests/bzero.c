/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/12 13:32:52 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_bzero.c"

int main()
{
	char str[] = "Coucou";
	char str2[] = "Coucou";
	int nbr = 4;

	bzero(str, nbr);
	printf("------\nbzero: %s\n", str);	
	ft_bzero(str2, nbr);
	printf("ft_bzero: %s\n––––\n", str2);
	return (0);
}
