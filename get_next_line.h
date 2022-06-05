/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:53:45 by kiijima           #+#    #+#             */
/*   Updated: 2022/06/05 19:57:12 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>

// #include <stdio.h>
// #include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*get_one_line(char *str);
char	*get_buffer_line(int fd, char *str);
char	*prepare_next_line(char *str);
int		ft_strchr(char *s, char c);
char	*ft_strdup(const char *src);

#endif
