/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:56:17 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/14 23:08:32 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	fill_directions(t_var **data)
{
	char	*arr[6];
	int		i;

	arr[0] = "NO";
	arr[1] = "SO";
	arr[2] = "WE";
	arr[3] = "EA";
	arr[4] = "F";
	arr[5] = "C";
	i = 1;
	(*data)->map = ft_lstnew_s(arr[0], NULL);
	while (i < 6)
		ft_lstadd_back_s(&(*data)->map, ft_lstnew_s(arr[i++], NULL));
}

int	check_first_argmts(t_var **data)
{
	t_map	*tmp;

	(*data)->i = 0;
	tmp = (*data)->map;
	while (tmp)
	{
		if (tmp->value)
			(*data)->i++;
		tmp = tmp->next;
	}
	if ((*data)->i != 6)
		return (0);
	return (1);
}

void	fill_values_direc(char **sub, t_map **mp)
{
	t_map	*tmp;

	tmp = *mp;
	while (tmp)
	{
		if (!ft_strcmp(sub[0], tmp->key))
		{
			if (tmp->value)
				free(tmp->value);
			tmp->value = ft_strtrim(sub[1], "\n \t");
		}
		tmp = tmp->next;
	}
}

void	check_direc(char **subl, t_var **mp)
{
	if (check_first_argmts(mp))
		return ;
	if (!ft_strcmp(subl[0], "NO"))
		fill_values_direc(subl, &(*mp)->map);
	else if (!ft_strcmp(subl[0], "SO"))
		fill_values_direc(subl, &(*mp)->map);
	else if (!ft_strcmp(subl[0], "WE"))
		fill_values_direc(subl, &(*mp)->map);
	else if (!ft_strcmp(subl[0], "EA"))
		fill_values_direc(subl, &(*mp)->map);
	else if (!ft_strcmp(subl[0], "F"))
		fill_values_direc(subl, &(*mp)->map);
	else if (!ft_strcmp(subl[0], "C"))
		fill_values_direc(subl, &(*mp)->map);
	else if (ft_strcmp(subl[0], "\n"))
		exit(ft_error("Error: Unrecognized map data!\n", 2));
}

void	check_map(t_var **data)
{
	char	*line;
	char	**sub_line;

	fill_directions(data);
	line = get_next_line((*data)->fd);
	while (line)
	{
		check_spaces(line);
		sub_line = ft_split(line, ' ');
		check_direc(sub_line, data);
		free(sub_line[0]);
		free(sub_line[1]);
		free(sub_line);
		if ((*data)->i == 6)
			break ;
		free(line);
		line = get_next_line((*data)->fd);
	}
	if (!check_first_argmts(data))
		exit(ft_error("Error: invalid map directions!\n", 2));
	check_file_path((*data)->map);
	check_colors(data);
	map_process(data, line);
}
