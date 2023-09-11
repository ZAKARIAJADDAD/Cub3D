/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:23:32 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/11 15:28:23 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    left_side(t_var *data)
{
    if (data->mouse_x < 0)
        mlx_mouse_move(data->mlx, data->mlx_win , data->x_screen / 2 , data->y_screen / 2);
    else if (data->mouse_x > data->x_screen || data->mouse_y > data->y_screen)
        mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2 , data->y_screen / 2);
    
    mlx_mouse_hide(data->mlx, data->mlx_win);
    data->player_pos.angle_in_radian -= convert_dgree(2);
    if (data->player_pos.angle_in_radian < 0)
        data->player_pos.angle_in_radian = 2 * PI;
}

void    right_side(t_var *data)
{
    if (data->mouse_x < 0)
        mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2 , data->y_screen / 2);
    else if (data->mouse_x > data->x_screen || data->mouse_y > data->y_screen)
        mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2 ,data->y_screen / 2);
    
    mlx_mouse_hide(data->mlx, data->mlx_win);
    data->player_pos.angle_in_radian += convert_dgree(2);
    if (data->player_pos.angle_in_radian > 2 * PI)
            data->player_pos.angle_in_radian = 0;
}

// void    rander_player(t_var *data)
// {
    // data->xpm_img.ptr1 = mlx_xpm_file_to_image(data->mlx , "xpm_fwwdile/frame2.xpm",  &data->xpm_img.width1 , &data->xpm_img.hight1);
    // data->xpm_img.ptr2 = mlx_get_data_addr(data->xpm_img.ptr1 , &data->xpm_img.bits_per_pixel , &data->xpm_img.line_length, &data->xpm_img.endian);
    // my_mlx_pixel_put();
    
    // mlx_put_image_to_window(data->mlx , data->mlx_win , data->xpm_img.ptr1, 500, 0);
// }

int	move_mouse(t_var *data)
{
	int old_mouse_x;
	int old_mouse_y;

	old_mouse_x = data->mouse_x;
	old_mouse_y = data->mouse_y;
	mlx_mouse_get_pos(data->mlx, data->mlx_win, &data->mouse_x, &data->mouse_y);
    if (data->mouse_x < old_mouse_x)
        left_side(data);
    else if (data->mouse_x > old_mouse_x)
        right_side(data);
    mlx_clear_window(data->mlx, data->mlx_win);
    rander_map2d(data);
    // rander_player(data);
   mini_map(data);
    return (1);
}