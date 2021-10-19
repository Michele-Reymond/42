/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:28:49 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/11 14:49:50 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../libft.h"
#include "../ft_isdigit.c"

int main()
{
	char a = '0';
	char b = '9';
	char c = ' ';
	char d = 'T';

	int e = ft_isdigit(a);
	int f = isdigit(a);
	printf("isdigit: %d, ft_isdigit: %d\n", f, e);

	int g = ft_isdigit(b);
	int h = isdigit(b);
	printf("isdigit: %d, ft_isdigit: %d\n", h, g);

	int i = ft_isdigit(c);
	int j = isdigit(c);
	printf("isdigit: %d, ft_isdigit: %d\n", j, i);

	int k = ft_isdigit(d);
	int l = isdigit(d);
	printf("isdigit: %d, ft_isdigit: %d\n", l, k);
}
