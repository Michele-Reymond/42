/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:10:14 by mreymond          #+#    #+#             */
/*   Updated: 2021/11/14 18:30:42 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char*s1, char*s2);
size_t	ft_strlen(char *str);
char	*clean_start_of_line(char *str);
char	*clean_end_of_line(char *str);

#endif