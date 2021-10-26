/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:34:02 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/26 18:44:52 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putendl_fd(char *s, int fd)
{
    int i;

    i = -1;
    if (s == NULL)
        return;
    while (s[++i] != '\0')
        write(fd, &s[i], 1);
    write(fd, "\n", 1);
}