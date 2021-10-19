/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:00:09 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/11 17:02:53 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../ft_isascii.c"

int main()
{
	int a = 128;
	char b = 0;
	char c = 127;

	int d = isascii(a);
	int e = ft_isascii(a);
	printf("isascii: %d, ft_isascii: %d\n", d, e);

	int f = isascii(b);
	int g = ft_isascii(b);
	printf("isascii: %d, ft_isascii: %d\n", f, g);

	int h = isascii(c);
	int i = ft_isascii(c);
	printf("isascii: %d, ft_isascii: %d\n", h, i);
}
