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

#include "../../cub3d_bonus.h"

void    player_position(t_var **data)
{
    int i;
    int j;

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

int dash_position(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[++i])
        if (s[i] == '.')
            return (i);
    return (42);
}

void    check_path_xpm(t_map *map)
{
    t_map   *tmp;
    char    *p;
    int     i;

    tmp = map;
    i = 0;
    while (tmp && i < 4)
    {
        p = tmp->value;
        p = ft_strchr(++p, '.');
        if (ft_strncmp(p ,".xpm", 4) || dash_position(tmp->value) == 0)
            exit(ft_error("Error : xpm extension missed!\n", 2));
        i++;
        tmp = tmp->next;
    }
}

void    check_file_path(t_map *map)
{
    t_map   *tmp;
    int     fd1;
    int     count;
    char    **path;
    char    *line;

    tmp = map;
    line = NULL;
    count = -1;
    check_path_xpm(map);
    while (tmp && ++count < 4)
    {
        line = ft_new_strjoin(line, tmp->value);
        tmp = tmp->next;
    }
    path = ft_split(line, '\n');
    free(line);
    count = -1;
    while(path[++count])
    {
        fd1 = open(path[count], O_RDONLY);
        if (fd1 == -1)
            exit(ft_error("Error : path file not found\n", 2));
        close(fd1);
        free(path[count]);
    }
    free(path);
}
