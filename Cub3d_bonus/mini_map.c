/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:30:06 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/12 20:49:30 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// void	rander_minimap(t_var *img)
// {
// 	img->player_pos.map2d_y = 0;
// 	while (img->map2d[img->player_pos.map2d_y])
// 	{
// 		img->player_pos.map2d_x = 0;
// 		while (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x])
// 		{
// 			if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ] == '1')
// 				fill_wall(img,(img->player_pos.map2d_y + 1) * 40,  (img->player_pos.map2d_x  + 1) * 40);
// 			else if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ] != '1')
// 				fill_ground(img,  (img->player_pos.map2d_y + 1) * 40, (img->player_pos.map2d_x + 1) * 40);
// 			img->player_pos.map2d_x++;
// 		}
// 		img->player_pos.map2d_y++;
// 	}
// 	my_mlx_pixel_put(img, img->player_2d.x_2d, img->player_2d.y_2d, BLACK);
// }

void	mini_map(t_var *data)
{
	int i;
	int k;
	int player_posx;
	int player_posy;
	int x_pos;
	int y_pos;

	i = 0;
	x_pos = data->player_pos.player_x - 100;
	y_pos = data->player_pos.player_y - 100;
	while (i <= 100)
	{
		k = 0;
		x_pos =data->player_pos.player_x - 50;
		while (k <= 100)
		{
			
			if (x_pos == data->player_pos.player_x && y_pos == data->player_pos.player_y)
				my_mlx_pixel_put(data, k, i, BLACK);
			if (data->map2d[y_pos / 50][x_pos / 50] == '1')
				my_mlx_pixel_put(data, k, i, GROUND);
			else if (data->map2d[y_pos / 50 ][x_pos / 50] != '1')
				my_mlx_pixel_put(data, k, i, DARK_TURQUOISE);
			x_pos++;
			k++;
			
		}
		y_pos++;
		i++;
	}
}
