/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:08 by mreymond          #+#    #+#             */
/*   Updated: 2022/01/18 13:46:36 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line_utils.c"

int main()
{
    int fichier = open("test.txt", O_RDONLY);
//    printf("%d", fichier);
    // printf("%s", get_next_line(1));
	char *str = NULL;

	str = get_next_line(fichier);
	printf("%s", str);
	while (str != 0)
	{
	 str = get_next_line(fichier); 
     printf("%s", str);
	}
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
}
