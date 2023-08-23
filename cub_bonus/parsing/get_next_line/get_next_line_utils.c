/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:03:07 by zjaddad           #+#    #+#             */
/*   Updated: 2023/08/10 10:27:53 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_old_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

char	*ft_new_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*pr;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	pr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!pr)
		return (NULL);
	while (s1[i])
	{
		pr[i] = s1[i];
		i++;
	}
	while (s2[j])
		pr[i++] = s2[j++];
	pr[i] = '\0';
	free(s1);
	return (pr);
}

char	*ft_strdup(const char *s1)
{
	char	*plloc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	if (s1[i] == '\n')
		plloc = malloc(i + 2);
	if (s1[i] == '\0')
		plloc = malloc(i + 1);
	if (!plloc)
		return (NULL);
	while (s1[j] != '\n' && s1[j])
	{
		plloc[j] = s1[j];
		j++;
	}
	if (s1[j] == '\n')
		plloc[j++] = '\n';
	plloc[j] = '\0';
	return (plloc);
}

void	*ft_calloc(size_t n, size_t size)
{
	int	*pcalloc;

	if (size != 0 && n > (SIZE_MAX / size))
		return (NULL);
	pcalloc = (int *)malloc(n * size);
	if (!pcalloc)
		return (NULL);
	ft_bzero(pcalloc, size * n);
	return (pcalloc);
}
