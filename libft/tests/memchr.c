/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/13 17:36:21 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../ft_memchr.c"

int main()
{
	char str1[] = "Coucou les copains";

	void *a = memchr(str1, 'p', 10);
	void *b = ft_memchr(str1, 'p', 10);

	printf("memchr: %s\n", a);
	printf("ft: %s\n", b);
}
