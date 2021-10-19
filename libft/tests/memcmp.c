/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/13 14:55:07 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../ft_memcmp.c"

int main()
{
	char str1[] = "\xff\xaa\xde\x12";
	char str2[] = "\xff\xaa\xde\x12MACOSAAAAA";

	int a = memcmp(str1, str2, 4);
	int b = ft_memcmp(str1, str2, 4);

	printf("memcmp: %d\n", a);
	printf("ft: %d\n", b);
}
