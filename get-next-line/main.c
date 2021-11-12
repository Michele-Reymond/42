/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:08 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/12 16:19:27 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line_utils.c"

int main()
{
    int fichier = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    printf("%s", get_next_line(fichier));
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
}
