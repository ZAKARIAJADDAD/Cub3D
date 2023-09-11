/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuer_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:01:02 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/10 18:41:53 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    fix_distortion(t_var *data)
{
    if (data->player_pos.ray_angle < data->player_pos.angle_in_radian)
		data->player_pos.distance = data->player_pos.distance * cos((data->player_pos.ray_angle - data->player_pos.angle_in_radian));
	else 
		data->player_pos.distance = data->player_pos.distance * cos((data->player_pos.angle_in_radian - data->player_pos.ray_angle));
    
    data->dda_data.projected_slice_height = GRIDE_SIZE / data->player_pos.distance * data->distance_to_projection_plane;
	if (data->dda_data.projected_slice_height < 0)
		data->dda_data.projected_slice_height = 0;
}

void    virtical_mapping(t_var *data)
{
	int k;
    
    if (cos(data->player_pos.ray_angle) > 0)
    {
        data->dda_data.y_tex = data->textuer2.textuer_y_hight / data->dda_data.projected_slice_height;
        k = get_pos(data->player_pos.y_virtical_line_end, data->textuer2.textuer_x_width);
        data->dda_data.texture_color = get_colors(&data->textuer2, k, data->dda_data.y_increament);
    }
    else
    {
        data->dda_data.y_tex = data->textuer3.textuer_y_hight / data->dda_data.projected_slice_height;
        k = get_pos(data->player_pos.y_virtical_line_end, data->textuer3.textuer_x_width);
        data->dda_data.texture_color = get_colors(&data->textuer3, k, data->dda_data.y_increament);
    }
}

void    horizontal_mapping(t_var *data)
{
	int k;
    
    if (sin(data->player_pos.ray_angle) > 0)
    {
        data->dda_data.y_tex = data->textuer.textuer_y_hight / data->dda_data.projected_slice_height;
        k = get_pos(data->player_pos.x_horizontal_line_end, data->textuer.textuer_x_width);
        data->dda_data.texture_color = get_colors(&data->textuer, k, data->dda_data.y_increament);
    }
    else
    {
        data->dda_data.y_tex = data->textuer1.textuer_y_hight / data->dda_data.projected_slice_height;
        k = get_pos(data->player_pos.x_horizontal_line_end, data->textuer1.textuer_x_width);
        data->dda_data.texture_color = get_colors(&data->textuer1, k, data->dda_data.y_increament);
    }
}