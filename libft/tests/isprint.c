/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:00:09 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/11 17:10:37 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../ft_isprint.c"

int main()
{
	char a = 127;
	char b = ' ';
	char c = 25;

	int d = isprint(a);
	int e = ft_isprint(a);
	printf("isprint: %d, ft_isprint: %d\n", d, e);

	int f = isprint(b);
	int g = ft_isprint(b);
	printf("isprint: %d, ft_isprint: %d\n", f, g);

	int h = isprint(c);
	int i = ft_isprint(c);
	printf("isprint: %d, ft_isprint: %d\n", h, i);
}
