/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/22 15:53:46 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_atoi.c"

int main()
{
	char	str[] = "     +2lyon";
	int 	a = atoi(str);
	int		b = ft_atoi(str);

	if (a == b)
	printf("OK\n");
	printf("atoi: %d\n", a);
	printf("ft: %d\n", b);
}	
