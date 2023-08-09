/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:30:59 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/09 10:23:13 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (free(ptr), NULL);
	while (s1[++i])
	{
		ptr[++j] = s1[i];
	}
	i = -1;
	while (s2[++i])
		ptr[++j] = s2[i];
	ptr[++j] = '\0';
	return (ptr);
}

char	*ft_strdup(char *source)
{
	char	*dest;
	size_t	i;

	if (!source)
		return (NULL);
	i = 0;
	dest = malloc(ft_strlen((char *)source) + 1);
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(source) && source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
