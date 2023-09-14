/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:28:05 by zjaddad           #+#    #+#             */
/*   Updated: 2023/08/13 15:28:05 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	ft_error(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return (1);
}

void	fill_x_y_map(char *line, t_var **data)
{
	int	len;

	len = ft_strlen(line);
	if (len > (*data)->x_width)
		(*data)->x_width = len;
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return (0);
}
