/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:45:34 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/09 14:22:19 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	first_rander_map2d(t_var *img)
{
	img->player_pos.map2d_y = 0;
	while (img->map2d[img->player_pos.map2d_y])
	{
		img->player_pos.map2d_x = 0;
		while (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x])
		{
			if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x] == '1')
				fill_wall(img,(img->player_pos.map2d_y + 1) * 50,  (img->player_pos.map2d_x + 1) * 50);
			else if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x] == '0')
				first_fill_ground(img,  (img->player_pos.map2d_y + 1) * 50, (img->player_pos.map2d_x + 1) * 50);
			else if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x] == 'P')
				player_fill(img, (img->player_pos.map2d_y + 1) * 50,  (img->player_pos.map2d_x + 1) * 50);
			img->player_pos.map2d_x++;
		}
		img->player_pos.map2d_y++;
	}
	// img->player_pos.x_line_end = img->player_pos.player_x;
	// img->player_pos.y_line_end = img->player_pos.player_y - 30;
	// first_draw_line(img);
	player_direction(img);
	my_mlx_pixel_put(img, img->player_pos.player_x, img->player_pos.player_y, 0x00000000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

void	clac_player_distence(t_var *data)
{
	double pd;
	double pe;
	
	double tmp 	= pow( (fabs(data->player_pos.player_x - data->player_pos.x_horizontal_line_end)) ,2);
	double tmp3 = pow( (fabs(data->player_pos.player_y - data->player_pos.y_horizontal_line_end)) ,2);
	double tmp2 = pow( (fabs(data->player_pos.player_x - data->player_pos.x_virtical_line_end)) ,2);
	double tmp4 = pow( (fabs(data->player_pos.player_y - data->player_pos.y_virtical_line_end)) ,2);
	
	pd = sqrt(tmp + tmp3);
	pe = sqrt(tmp2 + tmp4);
	if (pe < pd)
	{
		data->player_pos.x_line_end = data->player_pos.x_virtical_line_end;
		data->player_pos.y_line_end = data->player_pos.y_virtical_line_end;
	}
	else
	{
		data->player_pos.x_line_end = data->player_pos.x_horizontal_line_end;
		data->player_pos.y_line_end = data->player_pos.y_horizontal_line_end;
	}
}

int	rander_map2d(t_var *img)
{
	img->player_pos.map2d_y = 0;
	while (img->map2d[img->player_pos.map2d_y])
	{
		img->player_pos.map2d_x = 0;
		while (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ])
		{
			if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ] == '1')
				fill_wall(img,(img->player_pos.map2d_y + 1) * 50,  (img->player_pos.map2d_x  + 1) * 50);
			else if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ] != '1')
				fill_ground(img,  (img->player_pos.map2d_y + 1) * 50, (img->player_pos.map2d_x + 1) * 50);
			img->player_pos.map2d_x++;
		}
		img->player_pos.map2d_y++;
	}
	
	player_view_filed(img);
	// printf("test\n");
	my_mlx_pixel_put(img, img->player_pos.player_x, img->player_pos.player_y,0x00000000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
