/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor < agungor@student.42kocaeli.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:01 by agungor           #+#    #+#             */
/*   Updated: 2023/11/05 13:09:26 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char	*ft_read_left_str(char *left_str, int fd)
{
	char	*buffer;
	size_t	num_char_read;

	num_char_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && num_char_read)
	{
		num_char_read = read(fd, buffer, BUFFER_SIZE);
		if (num_char_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[num_char_read] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char static	*left_str;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_left_str(left_str, fd);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_get_new_str(left_str);
}
