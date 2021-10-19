/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/18 15:35:06 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../ft_strrchr.c"

int main()
{
	char src[] = "\0";

	char *a = strrchr(src, 'b');
	char *b = ft_strrchr(src, 'b');

	printf("strstr: %s\n", a);
	printf("ft: %s\n", b);

	if (a == b)
		printf("tout est ok");
}	
