#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char    *ft_strchr(char *s, int lettre);
char	*ft_strjoin(char*s1, char*s2);
size_t	ft_strlen(char *str);
char	*clean_start_of_line(char *str);
char	*clean_end_of_line(char *str);

#endif
