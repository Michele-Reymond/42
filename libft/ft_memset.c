/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:32:55 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/27 17:44:54 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*a;

	a = str;
	i = 0;
	while (i < n && n != 0)
	{
		a[i] = c;
		i++;
	}
	return (str);
}
