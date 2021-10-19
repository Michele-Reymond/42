/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/18 16:51:41 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../ft_strncmp.c"

int main()
{
	char str1[] = "the ";
	char str2[] = "ther";

	int a = strncmp(str1, str2, 4);
	int b = ft_strncmp(str1, str2, 4);

	printf("strncmp: %d\n", a);
	printf("ft: %d\n", b);
}	
