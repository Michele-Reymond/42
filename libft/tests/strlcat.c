/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/13 17:26:23 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_strlcat.c"

int main()
{
	char dst[0xF00] = "";
	char src[0xF00] = "thx to ntoniolo for this test !";
	char dst2[0xF00] = "";
	char src2[0xF00] = "thx to ntoniolo for this test !";
	int size = 4;

	int a = strlcat(dst, src, size);
	printf("strlcat: \n%s\n", dst);
	printf("%d\n", a);

	int b = ft_strlcat(dst2, src2, size);
	printf("––––\nft: \n%s\n", dst2);
	printf("%d\n", b);
}
