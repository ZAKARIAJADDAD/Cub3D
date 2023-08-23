/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:24:03 by zjaddad           #+#    #+#             */
/*   Updated: 2023/08/20 12:46:19 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void    check_characters(char *s)
{
    int     i;
    int     count;
    char    **ss;

    i = -1;
    count = 0;
    while(s[++i])
    {
        if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != '\n')
            exit(ft_error("Error: Invalid RGB value!\n", 2));
        if (s[i] == ',')
            count++;
    }
    if (count != 2)
        exit(ft_error("Error: Invalid RGB value!\n", 2));
    ss = ft_split(s, ',');
    i = -1;
    while(ss[++i])
    {
        count = ft_atoi(ss[i]);
        if (count < 0 || count > 255)
            exit(ft_error("Error: Invalid RGB value!\n", 2));
        free(ss[i]);
    }
    free(ss);
    system("leaks cub3D");
}

void    check_colors(t_map *map)
{
    t_map   *tmp;

    tmp = map->next->next->next->next;
    while (tmp)
    {
        check_characters(tmp->value);
        tmp = tmp->next;
    }
}
