/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:26:43 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/04 10:50:58 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_parsing(char *s, t_var **data)
{
	char	*new_s;

	new_s = ft_strchr(s, '.');
	if (new_s && !ft_strcmp(++new_s, "cub"))
	{
		*data = malloc(sizeof(t_var));
		if (!(*data))
			return ;
		(*data)->fd = 0;
		if (((*data)->fd = open(s, O_RDONLY)) == -1)
		{
			write(2, "Error: fd failed\n", 17);
			return ;
		}
		check_map(&(*data));
	}
	else
		write(2, "Error: File name must include an extension.\n", 44);
}

