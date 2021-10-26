/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:46:02 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/26 19:31:35 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putnbr_fd(int n, int fd)
{
    int i;
    char ptr[12];

    i = 0;
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n == 2147483647)
    {
        write(fd, "2147483647", 10);
        return;
    }
    if (n < 0)
    {
        n = -n;
        write(fd, "-", 1);
    }
    while (n > 0)
    {
        ptr[i] = n % 10 + 48;
        n /= 10;
        i++;
    }
    while( i > -1)
    {
        write(fd, &ptr[i], 1);
        i--;
    }
}

// int main()
// {
//     ft_putnbr_fd(2147483647, 1);
// }