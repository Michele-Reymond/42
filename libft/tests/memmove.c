/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/19 14:44:25 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_strlen.c"
#include "../ft_memmove.c"

int main()
{
	// char str1[30] = "Coucou les copains";
	// char str2[30] = "Coucou les copains";
	// char str3[30] = "Coucou les copains";
	// char str4[30] = "Coucou les copains";
	// int d = 18;

	char *src = "thanks to @apellicc for this test !\r\n";
	char dst1[0xF0];
	// char dst2[0xF0];
	int size = strlen(src);
	char *r1 = memmove(dst1, src, size);
	char *r2 = ft_memmove(dst1, src, size);

	// memmove(dst1, src, size);
	// ft_memmove(dst2, src, size);

	// printf("\nmemove dest: %s\n––––\n", dst1);
	// printf("ft_memove dest: %s\n––––\n", dst2);

	r1 = memmove("coucou", "", 0);
	r2 = ft_memmove("coucou", "", 0);

	printf("\nmemove r1: %s\n––––\n", r1);
	printf("ft_memove r2: %s\n––––\n", r2);

	// memmove(str1 + 8, str1, d);
	// ft_memmove(str2 + 8, str2, d);
	// printf("source plus petit : \nmemove dest: %s\n––––\n", str1);
	// printf("ft_memove dest: %s\n––––\n", str2);
	
	// memmove(str3, str3 + 4, d);
	// ft_memmove(str4, str4 + 4, d);
	// printf("source plus grand : \nmemove dest: %s\n––––\n", str3);
	// printf("ft_memove dest: %s\n––––\n", str4);
	
	return (0);
}
