/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:34:01 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 14:51:33 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_spaces(char *s)
{
	int		i;
	int		count;
	char	*p;

	i = -1;
	count = 0;
	p = ft_strtrim(s, " 	");
	while (p[++i])
	{
		if (p[i] == ' ' || p[i] == '	')
			count++;
	}
	if (count > 1)
		exit(ft_error("Error: multiple spaces insertion!\n", 2));
	free(p);
}
