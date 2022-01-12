/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:44:04 by mreymond          #+#    #+#             */
/*   Updated: 2022/01/12 15:49:55 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char a)
{
	write(1, &a, 1);
}

void printself(char *str, int cursor)
{
	int i;

	i = 0;
	while (i < cursor)
	{
		if (str[cursor] == str[i])
			return;
		i++;
	}
	ft_putchar(str[cursor]);
}

void printstr2(char *str2, char *str1, int cursor)
{
	int i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str2[cursor] == str1[i])
			return;
		i++;
	}
	printself(str2, cursor);
}

int main(int argv, char **argc)
{
	char *str1;
	char *str2;
	int i;

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
		printself(str1, i);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		printstr2(str2, str1, i);
		i++;
	}
	ft_putchar('\n');
	return (0);	
}

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Ecrire un programme nommé union qui prend en paramètre deux chaînes de
caractères et qui affiche, sans doublon, les caractères qui apparaissent dans
l'une ou dans l'autre.

L'affichage se fera dans l'ordre d'apparition dans la ligne de commande.

L'affichage doit etre suivi d'un retour à la ligne.

Si le nombre de paramètres transmis est différent de 2, le programme affiche
\n.

Exemple:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
