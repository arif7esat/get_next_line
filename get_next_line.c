/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor < agungor@student.42kocaeli.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:01 by agungor           #+#    #+#             */
/*   Updated: 2023/11/03 19:42:25 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
