/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/01 10:45:26 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_strlen.c"
#include "../ft_itoa.c"

int	main()
{
	int i;
	i = 0;
	char *str = ft_itoa(1);
	char *str1 = ft_itoa(-10);
	char *str2 = ft_itoa(-1);
	char *str3 = ft_itoa(0);
	char *str4 = ft_itoa(2147483647);
	char *str5 = ft_itoa(-2147483648);
	char *str6 = ft_itoa(10);
	char *str7 = ft_itoa(9123489);
	char *str8 = ft_itoa(-3435);

	printf("str: %s\n", str);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);
	printf("str4: %s\n", str4);
	printf("str5: %s\n", str5);
	printf("str6: %s\n", str6);
	printf("str7: %s\n", str7);
	printf("str8: %s\n", str8);

	free(str);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
	free(str8);
}	 