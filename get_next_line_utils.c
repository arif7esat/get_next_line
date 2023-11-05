/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor < agungor@student.42kocaeli.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:20:23 by agungor           #+#    #+#             */
/*   Updated: 2023/11/05 15:45:24 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*my_strjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	my_strjoin = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(my_strjoin))
		return (NULL);
	ft_memcpy(my_strjoin, s1, len1);
	ft_memcpy(my_strjoin + len1, s2, len2);
	my_strjoin[len1 + len2] = '\0';
	return (my_strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)s + i);
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

