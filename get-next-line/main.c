/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:08 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/07 18:45:40 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.c"

int main()
{
    // int fichier = open("test.txt", O_RDONLY);
	int fichier = open("test.txt", O_RDONLY);
    char *a;
    while ((a = get_next_line(fichier)) != NULL)
        printf("%s", a);
    free(a);
	close(fichier);
}