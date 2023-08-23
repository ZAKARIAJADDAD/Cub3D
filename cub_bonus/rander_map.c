/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:45:34 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/20 15:23:38 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


int	first_rander_map2d(t_var *img)
{ 

	img->player_pos.map2d_y = 0;
	while (img->map2d[img->player_pos.map2d_y])
	{
		img->player_pos.map2d_x = 0;
		while (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x])
		{
			if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x] == 'P')
				player_fill(img, (img->player_pos.map2d_y + 1) * 50,  (img->player_pos.map2d_x + 1) * 50);
			img->player_pos.map2d_x++;
		}
		img->player_pos.map2d_y++;
	}
	player_view_filed(img);
	// player_direction(img);
	// my_mlx_pixel_put(img, img->player_pos.player_x, img->player_pos.player_y, 0x00000000);
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
	
	data->player_pos.pd = sqrt(tmp + tmp3);
	data->player_pos.pe = sqrt(tmp2 + tmp4);
	if (data->player_pos.pe < data->player_pos.pd)
	{
		data->player_pos.x_line_end = data->player_pos.x_virtical_line_end;
		data->player_pos.y_line_end = data->player_pos.y_virtical_line_end;
		data->player_pos.distance = data->player_pos.pe;
	}
	else
	{
		data->player_pos.x_line_end = data->player_pos.x_horizontal_line_end;
		data->player_pos.y_line_end = data->player_pos.y_horizontal_line_end;
		data->player_pos.distance = data->player_pos.pd;
	}
}

int	move_mouse(t_var *data)
{
	int old_mouse_x;
	int old_mouse_y;

	old_mouse_x = data->mouse_x;
	old_mouse_y = data->mouse_y;
	mlx_mouse_get_pos(data->mlx, data->mlx_win, &data->mouse_x, &data->mouse_y);
	// if (data->mouse_x > 0 && data->mouse_x < data->x_screen && data->mouse_y > 0 && data->mouse_y < data->y_screen)
	// {
		if (data->mouse_x < old_mouse_x)
		{
			if (data->mouse_x < 0)
				mlx_mouse_move(data->mlx, data->mlx_win , data->x_screen / 2 , data->y_screen / 2);
			else if (data->mouse_x > data->x_screen)
				mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2 , data->y_screen / 2);
			
			mlx_mouse_hide(data->mlx, data->mlx_win);
			data->player_pos.angle_in_radian -= convert_dgree(1);
			if (data->player_pos.angle_in_radian < 0)
				data->player_pos.angle_in_radian = 2 * PI;
			mlx_clear_window(data->mlx, data->mlx_win);
			rander_map2d(data);

		}

		else if (data->mouse_x > old_mouse_x)
		{
			if (data->mouse_x < 0)
				mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2 , data->y_screen / 2);
			else if (data->mouse_x > data->x_screen)
				mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2 ,data->y_screen / 2);
			mlx_mouse_hide(data->mlx, data->mlx_win);
			data->player_pos.angle_in_radian += convert_dgree(1);
    		if (data->player_pos.angle_in_radian > 2 * PI)
       			 data->player_pos.angle_in_radian = 0;
			mlx_clear_window(data->mlx, data->mlx_win);
			rander_map2d(data);
		}

		// mlx_clear_window(data->mlx, data->mlx_win);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->xpm_img.ptr3 , 0 , 0);

	// }
		return 1;
}
int	rander_map2d(t_var *data)
{
	// printf("yes\n");
	// while(1)
	// {
	// }
	// mlx_clear_window(data->mlx, data->mlx_win);
	player_view_filed(data);
	// move_mouse(data);
	// mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
