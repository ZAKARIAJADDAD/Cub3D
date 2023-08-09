/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:25:41 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/01 18:32:36 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

int	x_width(char **p)
{
	int	i;
	int	j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
			j++;
		i++;
	}
	return (j * 50);
}

int	y_height(char **p)
{
	int	y;

	y = 0;
	while (p[y])
		y++;
	return (y * 50);
}

char	*join_utils(char *s1)
{
	s1 = malloc(sizeof(char *) * 1);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin_split(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;
	int		full_len;

	i = 0;
	j = 0;
	if (!s1)
		s1 = join_utils(s1);
	if (!s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(full_len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = 0;
	free(s1);
	return (p);
}

char	*ft_join(int fd)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = get_next_line(fd);
	if (str == NULL)
	{
	    printf("invalid map");
		exit(0);
	}
	while (str != NULL)
	{
		if (ft_strlen(str) <= 1)
			exit(0);
		tmp = ft_strjoin_split(tmp, str);
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
	return (tmp);
}

char	**ftt_split(t_var *data, int fd)
{
	int		i;
	char	*save;
	char	**test;

	i = 0;
	save = ft_join(fd);
	test = ft_split(save, '\n');
	data->tmp_arry = ft_split(save, '\n');
	data->tmp_arry2 = ft_split(save, '\n');
	free(save);
	save = NULL;
	return (test);
}