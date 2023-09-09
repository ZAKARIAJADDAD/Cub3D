/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 01:52:17 by zjaddad           #+#    #+#             */
/*   Updated: 2023/08/13 01:52:17 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	white_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return(0);
}

int	invalid_map(char **map, int i, int j)
{
	if (!i || !map[i + 1] || !map[i + 1][j] || (i && !map[i - 1][j]) || \
		!j || !map[i][j + 1] || (j && !map[i][j - 1]) || \
		map[i + 1][j] == ' ' || (i && map[i - 1][j] == ' ') || \
		map[i][j + 1] == ' ' || (j && map[i][j - 1] == ' '))
		return (1);
	return (0);
}

void	map_validation(t_var **data)
{
	(*data)->i = -1;
	(*data)->count = 0;
	while ((*data)->env2d[++(*data)->i])
	{
		(*data)->j = -1;
		while ((*data)->env2d[(*data)->i][++(*data)->j])
		{
			if (is_player((*data)->env2d[(*data)->i][(*data)->j]))
				(*data)->count++;
			if (!is_player((*data)->env2d[(*data)->i][(*data)->j]) && (*data)->env2d[(*data)->i][(*data)->j] != '0' &&\
				(*data)->env2d[(*data)->i][(*data)->j] != '1' && (*data)->env2d[(*data)->i][(*data)->j] != 'e' &&\
				(*data)->env2d[(*data)->i][(*data)->j] != 'd' && (*data)->env2d[(*data)->i][(*data)->j] != ' ')
				exit(ft_error("Error: Invalid map!\n", 2));
			if (((*data)->env2d[(*data)->i][(*data)->j] == 'd' || (*data)->env2d[(*data)->i][(*data)->j] == '0'\
				|| (*data)->env2d[(*data)->i][(*data)->j] == 'e' || is_player((*data)->env2d[(*data)->i][(*data)->j]))\
				&& invalid_map((*data)->env2d, (*data)->i, (*data)->j))
				exit(ft_error("Error: Invalid map!\n", 2));
		}
	}
	if ((*data)->count != 1)
		exit(ft_error("Error: Invalid map!\n", 2));
}

void	map_process(t_var **data, char *line)
{
	char	*line_mp;

	line_mp = NULL;
	while (line)
	{
		if (!white_spaces(line))
		{
			line = get_next_line((*data)->fd);
			continue ;
		}
		line_mp = ft_new_strjoin(line_mp, line);
		free(line);
		line = get_next_line((*data)->fd);
	}
	(*data)->env2d = ft_split(line_mp, '\n');
	free(line_mp);
	map_validation(data);
	player_position(data);
}