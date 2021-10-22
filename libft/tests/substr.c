/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/22 17:14:09 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_strlen.c"
#include "../ft_substr.c"

int main()
{
    char * str = strdup("1");
    char *s = ft_substr(str, 42, 42000000);
    printf("%s\n", s);
    free(s);
}	


// si start > longueur de str - 1
// on retourn juste str avec un \0

// si len > longueur de str len vaut la longueur de str?
// et start < size