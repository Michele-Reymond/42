/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/18 14:49:49 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_memcpy.c"

int main()
{
	char src1[] = "Coucou";
	char src2[] = "Coucou";
	char str[] = "Start stop!";
	char str2[] = "Start stop!";
	char dest1[100];
	char dest2[100];
	int d = 4;

	memcpy(dest2, src2, d);
	ft_memcpy(dest1, src1, d);
	printf("------\nmemcpy src: %s\n", src2);	
	printf("memcpy dest: %s\n––––\n", dest2);
	printf("------\nft_memcpy src: %s\n", src1);	
	printf("ft_memcpy dest: %s\n––––\n", dest1);
	
	printf("avant mmcpy: %s\n", str);
	memcpy(str, str + 6, 5);
	printf("apres mmcpy: %s\n", str);

	printf("avant ft_mmcpy: %s\n", str2);
	ft_memcpy(str2, str2 + 6, 5);
	printf("apres ft_mmcpy: %s\n", str2);
	
	return (0);
}
