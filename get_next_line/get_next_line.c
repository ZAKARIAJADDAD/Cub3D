/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:54:41 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/06 14:00:04 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static char	*line(int fd, char *save)
{
	int		s;
	char	*tmp;
	char	*buf;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	s = read(fd, buf, BUFFER_SIZE);
	if (buf[0] == '\n')
		exit (0);
	if (s < 0)
		return (free(save), free(buf), NULL);
	while (s > 0)
	{
		if (s < 0)
			return (free(buf), free(save), NULL);
		buf[s] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
		s = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (save);
}

static char	*fnk(char *save)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	if (!save)
		return (free(save), NULL);
	if (save[0] == '\0')
		return (0);
	while ((save[i] != '\n') && (save[i] != '\0'))
		i++;
	str = malloc(i + 2);
	if (!str)
		return (0);
	while (a <= i)
	{
		str[a] = save[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

static char	*find(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!save)
		return (free(save), NULL);
	while ((save[i] != '\n') && (save[i] != '\0'))
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	i++;
	tmp = ft_strdup(save + i);
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*lin;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
	{
		free(save);
		return (0);
	}
	save = line(fd, save);
	lin = fnk(save);
	save = find(save);
	return (lin);
}
