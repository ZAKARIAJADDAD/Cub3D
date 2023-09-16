/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:24:03 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/16 19:04:30 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	check_characters(char *s, t_var **data)
{
	char		**ss;
	static int	n;

	(*data)->i = -1;
	(*data)->count = 0;
	if (n == 0)
		n = -1;
	if (n >= 6)
		exit(ft_error("Error: Invalid RGB value!\n", 2));
	ss = ft_split(s, ',');
	(*data)->i = -1;
	while (ss[++(*data)->i] && n < 6)
	{
		if (!ft_isdigit(ss[(*data)->i][0]))
			exit(ft_error("Error: Invalid RGB value!\n", 2));
		(*data)->count = ft_atoi_m(ss[(*data)->i]);
		(*data)->rgb_n[++n] = (*data)->count;
		if ((*data)->count < 0 || (*data)->count > 255)
			exit(ft_error("Error: Invalid RGB value!\n", 2));
		free(ss[(*data)->i]);
	}
	free(ss);
}

void	check_colors(t_var **data)
{
	t_map		*tmp;
	char		*s;
	int			i;

	tmp = (*data)->map->next->next->next->next;
	while (tmp)
	{
		s = tmp->value;
		i = -1;
		(*data)->count = 0;
		while (s[++i])
		{
			if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != '\n')
				exit(ft_error("Error: Invalid RGB value!\n", 2));
			if (s[i] == ',')
				(*data)->count++;
		}
		if ((*data)->count != 2)
			exit(ft_error("Error: Invalid RGB value!\n", 2));
		check_characters(tmp->value, data);
		tmp = tmp->next;
	}
}
