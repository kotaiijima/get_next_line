/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:17:20 by kiijima           #+#    #+#             */
/*   Updated: 2022/06/03 09:44:49 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_next_line(int fd)
{
	static char	*s;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);

}

char	get_buffer_line(int fd, char *s)
{
	char	*buf;
	char	*save;
	ssize_t	read_line;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (read_line > 0 && ft_strchr(s, '\n') == NULL)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(buf);
			return (NULL);
		}
		save = buf;
	}
}
