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

int	invalid_map(char **map, int i, int j)
{
	if (!i || !map[i + 1] || !map[i + 1][j] || (i && !map[i - 1][j]) || \
		!j || !map[i][j + 1] || (j && !map[i][j - 1]) || \
		map[i + 1][j] == ' ' || (i && map[i - 1][j] == ' ') || \
		map[i][j + 1] == ' ' || (j && map[i][j - 1] == ' '))
		return (1);
	return (0);
}

void	inside_map_verfication(t_2var **data)
{
	while ((*data)->env2d[(*data)->i][++(*data)->j])
	{
		if (is_player((*data)->env2d[(*data)->i][(*data)->j]))
			(*data)->count++;
		if (!is_player((*data)->env2d[(*data)->i][(*data)->j]) && \
			(*data)->env2d[(*data)->i][(*data)->j] != '0' && \
			(*data)->env2d[(*data)->i][(*data)->j] != '1' && \
			(*data)->env2d[(*data)->i][(*data)->j] != 'e' && \
			(*data)->env2d[(*data)->i][(*data)->j] != 'd' && \
			(*data)->env2d[(*data)->i][(*data)->j] != ' ')
			exit(ft_error("Error: Invalid map1!\n", 2));
		if (((*data)->env2d[(*data)->i][(*data)->j] == 'd' \
			|| (*data)->env2d[(*data)->i][(*data)->j] == '0' \
			|| (*data)->env2d[(*data)->i][(*data)->j] == 'e' || \
			is_player((*data)->env2d[(*data)->i][(*data)->j])) \
			&& invalid_map((*data)->env2d, (*data)->i, (*data)->j))
			exit(ft_error("Error: Invalid map222!\n", 2));
	}
}

void	map_validation(t_2var **data)
{
	(*data)->i = -1;
	(*data)->count = 0;
	while ((*data)->env2d[++(*data)->i])
	{
		(*data)->j = -1;
		inside_map_verfication(data);
	}
	if ((*data)->count != 1)
		exit(ft_error("Error: Invalid map3!\n", 2));
}

void	map_process(t_2var **data, char *line)
{
	(*data)->y_height = 0;
	(*data)->line_mp = NULL;
	while (line)
	{
		if (!white_spaces(line) && !(*data)->line_mp)
		{
			free(line);
			line = get_next_line((*data)->fd);
			continue ;
		}
		if (line[0] == '\n' && (*data)->line_mp && !rest_of_map(&line, data))
			exit(ft_error("Error: Map error!", 2));
		(*data)->y_height++;
		fill_x_y_map(line, data);
		(*data)->line_mp = ft_new_strjoin((*data)->line_mp, line);
		free(line);
		line = get_next_line((*data)->fd);
	}
	(*data)->env2d = ft_split((*data)->line_mp, '\n');
	if (!(*data)->env2d || !(*data)->env2d[0])
		exit(ft_error("Error: Map not found!", 2));
	free((*data)->line_mp);
	map_validation(data);
	player_position(data);
}
