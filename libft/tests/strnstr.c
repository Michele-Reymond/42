/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/19 18:11:25 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../ft_strnstr.c"

int main()
{
	char hay[] = "abFbFFcd";
	char need[] = "FF";

	char *a = strnstr(hay, need, 10);
	char *b = ft_strnstr(hay, need, 10);

	printf("strnstr: %s\n", a);
	printf("ft: %s\n", b);
	printf("len: %lu\n", strlen(hay));
}	
