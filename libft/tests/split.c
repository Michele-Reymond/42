/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/30 15:31:02 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_strlen.c"
#include "../ft_strlcpy.c"
#include "../ft_substr.c"
#include "../ft_calloc.c"
#include "../ft_strtrim.c"
#include "../ft_split.c"

int	main()
{
	int i;
	i = 0;
	char **str = ft_split("     ", ' ');
	printf("sortie1: %s\n", str[0]);
	printf("sortie2: %s\n", str[1]);
	printf("sortie3: %s\n", str[2]);
	printf("sortie4: %s\n", str[3]);
	printf("sortie5: %s\n", str[4]);
	printf("sortie6: %s\n", str[5]);
	printf("sortie7: %s\n", str[6]);
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}	 
