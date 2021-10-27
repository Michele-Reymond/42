/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/27 17:08:36 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../ft_strnstr.c"
#include "../ft_strlen.c"

int main()
{
	char hay[30] = "aaabcabcd";
	char need[14] = "a";

	char *a = strnstr(hay, need, 1);
	char *b = ft_strnstr(hay, need, 1);

	if (b == hay + 1)
		printf("nickel bleu ciel\n");
	printf("strnstr: %s\n", a);
	printf("ft: %s\n", b);
	printf("len: %lu\n", strlen(hay));
}
