/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/27 13:45:20 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_strlen.c"
#include "../ft_substr.c"
#include "../ft_strtrim.c"

int	main()
{
	char *str = ft_strtrim("  \n\n\nHello \t  Please\n Trim me !\n\n\n\n  ", "\n ");
	printf("%s\n", str);
	printf("___________\n%s\n", "\n\n\nHello \t  Please\n Trim me !\n\n\n\n");
}	 



// jusqua la fin de set:
// si char1 == set1 on fait i++ et on sort de la boucle;
// sinon on fait set++;
// si char1 == set2 on fait i++ et on sort de la boucle;
// sinon on fait set++;