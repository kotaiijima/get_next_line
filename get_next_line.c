/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:17:20 by kiijima           #+#    #+#             */
/*   Updated: 2022/06/05 19:56:55 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == (c))
			return (1);
		i++;
	}
	return (0);
}

char	*get_buffer_line(int fd, char *str)
{
	char	*buf;
	ssize_t	read_line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_line = 1;
	while (ft_strchr(str, '\n') == 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line <= 0)
			break ;
		buf[read_line] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (read_line < 0)
		return (NULL);
	return (str);
}

char	*get_one_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + (str[i] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*prepare_next_line(char *str)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	next = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (next == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		next[j] = str[i + j];
		j++;
	}
	next[j] = '\0';
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_buffer_line(fd, str);
	if (str == NULL)
		return (NULL);
	line = get_one_line(str);
	str = prepare_next_line(str);
	return (line);
}

// int main()
// {
// 	size_t	i;
// 	int		fd;
// 	char *s;

// 	fd = open("fileA",O_RDONLY);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (s == NULL || s[0] == '\0')
// 			printf("\n");
// 		s = get_next_line(fd);
// 		printf("line%zu : %s", i, s);
// 		i++;
// 	}
// }
