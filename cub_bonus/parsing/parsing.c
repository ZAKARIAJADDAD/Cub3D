/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:26:43 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/12 04:44:57 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	map_parsing(char *s, t_var **data)
{
	char	*new_s;

	new_s = ft_strrchr(s, '.');
	if (new_s && !ft_strcmp(++new_s, "cub"))
	{
		*data = malloc(sizeof(t_var));
		if (!(*data))
			return ;
		(*data)->fd = 0;
		(*data)->fd = open(s, O_RDONLY);
		if ((*data)->fd == -1)
			exit(ft_error("Error: fd failed\n", 2));
		check_map(&(*data));
	}
	else
		exit(ft_error("Error: File name must include an extension.\n", 2));
}
