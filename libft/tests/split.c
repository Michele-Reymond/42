/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:06 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/25 17:51:11 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ft_strlen.c"
#include "../ft_strlcpy.c"
#include "../ft_substr.c"
#include "../ft_strtrim.c"
#include "../ft_split.c"

int	main()
{
	int i;
	i = 0;
	char **str = ft_split("         ", ' ');
	// printf("sortie: %s\n", str[0]);
	// printf("sortie: %s\n", str[1]);
	// printf("sortie: %s\n", str[2]);
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}	 
