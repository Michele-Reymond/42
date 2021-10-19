/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:15:10 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/11 17:31:32 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_strlen.c"

int main(int argc, char **argv)
{
	(void) argc;
	char *a = argv[1];

	int b = strlen(a);
	int c = ft_strlen(a);
	printf("strlen: %d, ft_strlen: %d\n", b, c);
}
