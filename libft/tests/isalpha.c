/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/11 14:49:23 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../libft.h"
#include "../ft_isalpha.c"

int main()
{
	char c = 'y';
	char d = ' ';
	char z = 'Z';
	char e = '+';

	int a = ft_isalpha(c);
	int b = isalpha(c);
	printf("isalpha: %d, ft_isalpha: %d\n", b, a);

	int f = ft_isalpha(d);
	int g = isalpha(d);
	printf("isalpha: %d, ft_isalpha: %d\n", g, f);

	int h = ft_isalpha(z);
	int i = isalpha(z);
	printf("isalpha: %d, ft_isalpha: %d\n", i, h);
	
	int j = ft_isalpha(e);
	int k = isalpha(e);
	printf("isalpha: %d, ft_isalpha: %d\n", k, j);
}
