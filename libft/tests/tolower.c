/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/12 16:29:35 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../ft_tolower.c"

int main()
{
	char c = 'y';
	char d = ' ';
	char z = 'Z';

	char a = ft_tolower(c);
	char b = tolower(c);
	printf("tolower: %c, ft_tolower: %c\n", b, a);

	char f = ft_tolower(d);
	char g = tolower(d);
	printf("tolower: %c, ft_tolower: %c\n", g, f);

	char h = ft_tolower(z);
	char i = tolower(z);
	printf("tolower: %c, ft_tolower: %c\n", i, h);
}
