/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/12 16:18:48 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../ft_toupper.c"

int main()
{
	char c = 'y';
	char d = ' ';
	char z = 'Z';

	char a = ft_toupper(c);
	char b = toupper(c);
	printf("toupper: %c, ft_toupper: %c\n", b, a);

	char f = ft_toupper(d);
	char g = toupper(d);
	printf("toupper: %c, ft_toupper: %c\n", g, f);

	char h = ft_toupper(z);
	char i = toupper(z);
	printf("toupper: %c, ft_toupper: %c\n", i, h);
}
