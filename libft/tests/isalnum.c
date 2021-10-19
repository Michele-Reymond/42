/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:42:58 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/11 14:48:39 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../libft.h"
#include "../ft_isalnum.c"

int main ()
{
	char a = 'a';
	char b = 'B';
	char c = '6';
	char d = ']';

	int e = ft_isalnum(a);
	int f = isalnum(a);
	printf("isalnum: %d, ft_isalnum: %d\n", f, e);

	int g = ft_isalnum(b);
	int h = isalnum(b);
	printf("isalnum: %d, ft_isalnum: %d\n", h, g);

	int i = ft_isalnum(c);
	int j = isalnum(c);
	printf("isalnum: %d, ft_isalnum: %d\n", j, i);

	int k = ft_isalnum(d);
	int l = isalnum(d);
	printf("isalnum: %d, ft_isalnum: %d\n", k, l);
}
