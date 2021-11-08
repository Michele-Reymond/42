/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:08 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/08 18:07:01 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line_utils.c"

int main()
{
    int fichier = open("test.txt", O_RDONLY);
    char *a;
    char *b;
    // while ((a = get_next_line(fichier)) != NULL)
        // printf("%s", a);
    a = get_next_line(fichier);
    b = get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // free(a);
	close(fichier);
    // printf("Entrée standard : \n");
    // printf("%s", a);
    // printf("%s", b);
}