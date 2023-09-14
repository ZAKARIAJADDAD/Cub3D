/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:26:43 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/14 22:52:45 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_parsing(char *s, t_2var **data)
{
	char	*new_s;

	new_s = ft_strrchr(s, '.');
	if (new_s && !ft_strcmp(++new_s, "cub"))
	{
		(*data)->fd = 0;
		(*data)->fd = open(s, O_RDONLY);
		if ((*data)->fd == -1)
			exit(ft_error("Error: fd failed\n", 2));
		check_map(&(*data));
	}
	else
		exit(ft_error("Error: File name must include an extension.\n", 2));
}
