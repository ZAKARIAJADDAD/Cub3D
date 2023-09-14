/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:02:44 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 23:40:04 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*pr;

	i = 0;
	pr = (char *)s;
	while (i < n)
	{
		pr[i] = 0;
		i++;
	}
}

char	*read_line(int fd, char *sv)
{
	char	*buf;
	int		by;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	by = 1;
	while (!ft_old_strchr(buf, '\n'))
	{
		by = read(fd, buf, BUFFER_SIZE);
		if (by <= 0)
			break ;
		buf[by] = '\0';
		sv = ft_new_strjoin(sv, buf);
	}
	free(buf);
	return (sv);
}

char	*next_line(char *rest)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (rest[i] == '\n')
		i++;
	if ((ft_strlen(rest) - i) == 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i) + 2);
	if (!s)
		return (NULL);
	while (rest[i])
		s[j++] = rest[i++];
	s[j] = '\0';
	free(rest);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*hndl;
	char		*p_res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	hndl = read_line(fd, hndl);
	if (!hndl)
		return (NULL);
	p_res = ft_strdup(hndl);
	hndl = next_line(hndl);
	return (p_res);
}
