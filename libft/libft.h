/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:50:32 by mreymond          #+#    #+#             */
/*   Updated: 2021/10/27 11:03:34 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

#ifndef LIBFT_H
# define LIBFT_H

int ft_isalpha(int c);
int ft_isdigit(int d);
int	ft_isascii(int a);
int	ft_isalnum(int a);
int	ft_isprint(int p);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_atoi(const char *str);
void *ft_memset(void *str, int c, unsigned int n);
void ft_bzero(void *str, unsigned int n);
void	*ft_memchr(const void *s, int c, unsigned int n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize);
unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize);
unsigned int	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
