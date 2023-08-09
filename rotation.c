/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:19:16 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/09 13:43:53 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rotate_left(t_var *data)
{
   
    // else if (data->player_pos.angle_in_radian < 0)
    //     data->player_pos.angle_in_radian += 6.28319;
    // else 

    data->player_pos.angle_in_radian -= ROTATE_ANGLE;
    if (data->player_pos.angle_in_radian < 0)
        data->player_pos.angle_in_radian = 6.28319;
    
    // data->player_pos.save_x_inc = cos(data->player_pos.angle_in_radian) * data->player_pos.line_lenth;
    // data->player_pos.save_y_inc = sin(data->player_pos.angle_in_radian) * data->player_pos.line_lenth;
    // data->player_pos.x_line_end = data->player_pos.player_x  + data->player_pos.save_x_inc;
    // data->player_pos.y_line_end = data->player_pos.player_y + data->player_pos.save_y_inc;
}

void    rotate_right(t_var *data)
{
  
    // else if (data->player_pos.angle_in_radian < 0)
    //     data->player_pos.angle_in_radian += 6.28319;
    // else 
    // printf("p%d\n",data->player_pos.angle_in_radian);
    data->player_pos.angle_in_radian += ROTATE_ANGLE;
    if (data->player_pos.angle_in_radian > 6.28319)
        data->player_pos.angle_in_radian = 0;
    
    // data->player_pos.save_x_inc = cos(data->player_pos.angle_in_radian) * data->player_pos.line_lenth;
    // data->player_pos.save_y_inc = sin(data->player_pos.angle_in_radian) * data->player_pos.line_lenth;
    // data->player_pos.x_line_end = data->player_pos.player_x + data->player_pos.save_x_inc;
    // data->player_pos.y_line_end = data->player_pos.player_y + data->player_pos.save_y_inc;
}