/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:34:01 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/12 04:17:32 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

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
