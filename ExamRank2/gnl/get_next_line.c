#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *str, int lettre)
{
	char c;

	if (str == NULL)
		return (NULL);
	c = lettre;
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char *strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *joined;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (joined);
}

char *clean_end_of_line(char *str)
{
	char *cleaned;
	int i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	cleaned = (char *)malloc(sizeof(char) * i + 2);
	if (cleaned == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cleaned[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		cleaned[i] = str[i];
		i++;
	}
	cleaned[i] = '\0';
	return (cleaned);
}

char *clean_start_of_line(char *str)
{
	char *cleaned;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	cleaned = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (cleaned == NULL)
		return (NULL);
	i++;
	while (str[i] && str[i] != '\0')
	{
		cleaned[j] = str[i];
		i++;
		j++;
	}
	cleaned[j] = '\0';
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (cleaned);
}

char *get_next_line(int fd)
{
	static char *line;
	char *buffer;
	char *tmp;
	int lecture;
	char *returned_line;

	lecture = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	tmp = line;
	while (lecture != 0 && ft_strchr(tmp, '\n') == NULL)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[lecture] = '\0';
		if (!tmp)
		{
			tmp = (char *)malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		tmp = strjoin(tmp, buffer);
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	returned_line = clean_end_of_line(tmp);
	line = clean_start_of_line(tmp);
	return (returned_line);
}

int main()
{
	int fd;
	char *line;
	int d;

	d = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line %d : %s", d, line);
	line = get_next_line(fd);
	d++;
	printf("line %d : %s", d, line);
}
