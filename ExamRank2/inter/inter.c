/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:50:14 by mreymond          #+#    #+#             */
/*   Updated: 2022/01/17 16:05:48 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char a)
{
	write(1, &a, 1);
}

int check_both(char *str, char lettre)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (lettre == str[i])
			return (1);
		i++;
	}
	return (0);
}

void printself(char* str, int cursor)
{
	int i;

	i = 0;
	while (i < cursor)
	{
		if (str[i] == str[cursor])
			return;
		i++;
	}
	ft_putchar(str[cursor]);
}

int main (int argv, char **argc)
{
	char *str1;
	char *str2;
	int	i;

	i = 0;
	str1 = argc[1];
	str2 = argc[2];
	if (argv != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	while (str1[i] != '\0')
	{
		if (check_both(str2, str1[i]))
			printself(str1, i);
		i++;
	}
	ft_putchar('\n');
	return (0);
}


/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Écrire un programme qui prend en paramètres deux chaînes de caractères et qui
affiche sans doublon les caractères communs aux deux chaînes.

L'affichage se fera dans l'ordre d'apparition dans la premiere chaîne.
L'affichage doit être suivi d'un '\n'.

Si le nombre de paramètres transmis est différent de 2, le programme affiche
'\n'.

Exemples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/
