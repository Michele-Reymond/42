/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/13 16:45:57 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
 #include "../ft_strlcpy.c"

int main()
{
	char dst[30] = "coucou les amis";
	char src[30] = "hello les copains";
	char dst2[30] = "coucou les amis";
	char src2[30] = "hello les copains";
	int size = 30;

	int a = strlcpy(dst, src, size);
	printf("strlcpy: \n%s\n", dst);
	printf("%d\n", a);

	int b = ft_strlcpy(dst2, src2, size);
	printf("––––\nft: \n%s\n", dst2);
	printf("%d\n", b);
}
