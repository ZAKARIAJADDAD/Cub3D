/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:37:23 by zjaddad           #+#    #+#             */
/*   Updated: 2023/08/13 16:37:23 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	player_position(t_2var **data)
{
	int	i;
	int	j;

	i = -1;
	while ((*data)->env2d[++i])
	{
		j = -1;
		while ((*data)->env2d[i][++j])
		{
			if (is_player((*data)->env2d[i][j]))
			{
				(*data)->player_pos.player_x = i;
				(*data)->player_pos.player_y = j;
				return ;
			}
		}
	}
}

int	dash_position(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == '.')
			return (i);
	return (42);
}

void	check_path_xpm(t_2map *map)
{
	t_2map	*tmp;
	char	*p;
	int		i;

	tmp = map;
	i = 0;
	while (tmp && i < 4)
	{
		p = tmp->value;
		p = ft_strrchr(p, '.');
		if (!p)
			exit(ft_error("Error : Empty path image!\n", 2));
		if (ft_strncmp(p, ".xpm", 4) || dash_position(tmp->value) == 0)
			exit(ft_error("Error : xpm extension missed!\n", 2));
		i++;
		tmp = tmp->next;
	}
}

void	check_file_path(t_2map *map)
{
	t_2map	*tmp;
	int		fd1;
	int		count;
	char	*line;

	tmp = map;
	line = NULL;
	count = -1;
	check_path_xpm(map);
	count = -1;
	tmp = map;
	while (tmp && ++count < 4)
	{
		fd1 = open(tmp->value, O_RDONLY);
		if (fd1 == -1)
			exit(ft_error("Error : path file not found\n", 2));
		close(fd1);
		tmp = tmp->next;
	}
}

int	rest_of_map(char **line, t_2var **data)
{
	int	i;

	i = -1;
	*line = get_next_line((*data)->fd);
	while (*line)
	{
		while (*line[i++])
			if (*line[i] != '\n' || *line[i] != '\t' || *line[i] != ' ')
				return (0);
		*line = get_next_line((*data)->fd);
	}
	return (1);
}
