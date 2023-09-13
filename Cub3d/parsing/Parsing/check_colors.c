/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:24:03 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 19:06:13 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	fill_colors(t_2var **data , int i, int j, int count)
{
	if (i == 0 && j == 0)
		(*data)->ceiling_r = count;
	if (i == 1 && j == 0)
		(*data)->ceiling_g = count;
	if (i == 2 && j == 0)
		(*data)->ceiling_b = count;
	if (i == 0 && j == 1)
		(*data)->floor_r = count;
	if (i == 1 && j == 1)
		(*data)->floor_g = count;
	if (i == 2 && j == 1)
		(*data)->floor_b = count;
}

void	check_characters(char *s, int i, int count, t_2var **data)
{
	char	**ss;
	static int j = 0;
	i = -1;
	count = 0;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != '\n')
			exit(ft_error("Error: Invalid RGB value1!\n", 2));
		if (s[i] == ',')
			count++;
	}
	if (count != 2)
		exit(ft_error("Error: Invalid RGB value2!\n", 2));
	ss = ft_split(s, ',');
	i = -1;
	while (ss[++i])
	{
		if (!ft_isdigit(ss[i][0]))
			exit(ft_error("Error: Invalid RGB value3'!\n", 2));
		count = ft_atoi(ss[i]);
		fill_colors(data,i,j, count);
		if (count < 0 || count > 255)
			exit(ft_error("Error: Invalid RGB value3!\n", 2));
		free(ss[i]);
	}
	j++;
	free(ss);
}

void	check_colors(t_2map *map, t_2var **data)
{
	t_2map	*tmp;
	int		i;
	int		count;

	i = -1;
	count = 0;
	tmp = map->next->next->next->next;
	while (tmp)
	{
		check_characters(tmp->value, i, count, data);
		tmp = tmp->next;
	}
}
