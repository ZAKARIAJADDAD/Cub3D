/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:45:34 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/12 20:52:03 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_map_position(t_var *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map2d[y])
	{
		x = 0;
		while (data->map2d[y][x])
		{
			if (data->map2d[y][x] == 'N' || data->map2d[y][x] == 'W'
				|| data->map2d[y][x] == 'E' || data->map2d[y][x] == 'S')
			{
				data->player_pos.player_x = (x * GRIDE_SIZE) + 25;
				data->player_pos.player_y = (y * GRIDE_SIZE) + 25;
				player_direction(data, data->map2d[y][x]);
			}
			x++;
		}
		y++;
	}
}

// int	first_rander_map2d(t_var *img)
// {
// 	img->player_pos.map2d_y = 0;
// 	while (img->map2d[img->player_pos.map2d_y])
// 	{
// 		img->player_pos.map2d_x = 0;
// 		while (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x])
// 		{
// 			if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x] == 'P')
// 				player_fill(img, (img->player_pos.map2d_y + 1) * 50,
// 					(img->player_pos.map2d_x + 1) * 50);
// 			img->player_pos.map2d_x++;
// 		}
// 		img->player_pos.map2d_y++;
// 	}
// 	return (0);
// }

void	clac_player_distence(t_var *data)
{
	data->player_pos.horizontal_distance = sqrt(pow((data->player_pos.player_x
					- data->player_pos.x_horizontal_line_end), 2)
			+ pow((data->player_pos.player_y
					- data->player_pos.y_horizontal_line_end), 2));
	data->player_pos.virtical_distance = sqrt(pow((data->player_pos.player_x
					- data->player_pos.x_virtical_line_end), 2)
			+ pow((data->player_pos.player_y
					- data->player_pos.y_virtical_line_end), 2));
	if (data->player_pos.virtical_distance < data->player_pos.horizontal_distance)
	{
		data->player_pos.x_line_end = data->player_pos.x_virtical_line_end;
		data->player_pos.y_line_end = data->player_pos.y_virtical_line_end;
		data->player_pos.distance = data->player_pos.virtical_distance;
	}
	else
	{
		data->player_pos.x_line_end = data->player_pos.x_horizontal_line_end;
		data->player_pos.y_line_end = data->player_pos.y_horizontal_line_end;
		data->player_pos.distance = data->player_pos.horizontal_distance;
	}
}


int	rander_map2d(t_var *data)
{
	player_view_filed(data);
	return (0);
}
