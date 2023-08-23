/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_2dmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:45:32 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/20 12:45:38 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    clac_2dplayer_distence(t_var *data)
{
    double pd;
	double pe;
	double tmp 	= pow( (fabs(data->player_2d.x_2d - data->player_2d.horizontal_x2d_end)) ,2);
	double tmp3 = pow( (fabs(data->player_2d.y_2d - data->player_2d.horizontal_y2d_end)) ,2);
	double tmp2 = pow( (fabs(data->player_2d.x_2d - data->player_2d.virtical_x2d_end)) ,2);
	double tmp4 = pow( (fabs(data->player_2d.y_2d - data->player_2d.virtical_y2d_end)) ,2);
	
	data->player_2d.ph = sqrt(tmp + tmp3);
	data->player_2d.pv = sqrt(tmp2 + tmp4);
	if (data->player_2d.pv < data->player_2d.ph)
	{
		data->player_2d.calc_xend = data->player_2d.virtical_x2d_end;
		data->player_2d.calc_yend = data->player_2d.virtical_y2d_end;
		data->player_2d.ray_lenth = data->player_2d.pv;
	}
	else
	{
		data->player_2d.calc_xend = data->player_2d.horizontal_x2d_end;
		data->player_2d.calc_yend = data->player_2d.horizontal_y2d_end;
		data->player_2d.ray_lenth = data->player_2d.ph;
	}
}

void    horizontal_2d(t_var *data)
{
    double alpha_y;
	double alpha_x;
	double dy;
	double dx;
	double ys;
	double xs;
	double old_xs;
	double old_ys;

	// data->player_2d.horizontal_x2d_end = data->x_screen - 1;
    // data->player_2d.horizontal_y2d_end = data->y_screen - 1;
	if(sin(data->player_pos.ray_angle) == 0 || cos(data->player_pos.ray_angle) == 0)
		return;

	if (data->player_pos.ray_angle > 0 && data->player_pos.ray_angle <=  convert_dgree(180))
		alpha_y = (floor((int)data->player_2d.y_2d / 40) * 40) + 40;
	else
		alpha_y = (floor((int)data->player_2d.y_2d / 40) * 40) -0.001;
	
	alpha_x =  (data->player_2d.y_2d - alpha_y) / tan(data->player_pos.angle_in_radian);

	if (data->player_pos.ray_angle >=  convert_dgree(90) && data->player_pos.ray_angle <= convert_dgree(270))
		alpha_x = data->player_2d.x_2d - fabs(alpha_x);
	else 
		alpha_x = data->player_2d.x_2d + fabs(alpha_x);
	
	if (data->player_pos.ray_angle >= 0 && data->player_pos.ray_angle <= convert_dgree(180))
		ys = 40;	
	else
		ys = -40;
                                                     
	xs = ys / tan(data->player_pos.angle_in_radian);
		
	if (alpha_x < 0 || alpha_y < 0 || alpha_x > data->x_width || alpha_y >data->y_height)
	{
		data->player_2d.horizontal_x2d_end = INT_MAX;
		data->player_2d.horizontal_y2d_end = INT_MAX;
		return;
	}
	if (data->map2d[(int)alpha_y / 40][(int)alpha_x /40] == '1')
	{
		data->player_2d.horizontal_x2d_end = alpha_x;
		data->player_2d.horizontal_y2d_end = alpha_y;
	}
	else
	{
		old_xs = xs + alpha_x;
		old_ys = alpha_y + ys;
		while(1)
		{
			if (old_xs < 0)
				old_xs = xs;
			if (old_ys < 0)
				old_ys = ys;
			if (old_xs > 0 && old_ys > 0 && old_xs < data->x_width && old_ys < data->y_height)
			{
				if (data->map2d[(int)old_ys  / 40][(int)old_xs  / 40] != '1')
				{
					old_xs += xs;
					old_ys += ys;
				}
				else if (data->map2d[(int)old_ys  / 40][(int)old_xs  / 40] == '1')
				{
					data->player_2d.horizontal_x2d_end  = old_xs;
					data->player_2d.horizontal_y2d_end  = old_ys;
					break;
				}
			}
			else
			{
				data->player_2d.horizontal_x2d_end = INT_MAX;
				data->player_2d.horizontal_y2d_end = INT_MAX;
				return;
			}
		}
	}
}

void    virtical_2d(t_var *data)
{
    double alpha_y;
	double alpha_x;
	double dy;
	double dx;
	double ys;
	double xs;
	double old_xs;
	double old_ys;
	
	data->player_2d.virtical_x2d_end = INT_MAX ;
	data->player_2d.virtical_y2d_end= INT_MAX ;
	if(sin(data->player_pos.ray_angle) == 0 || cos(data->player_pos.ray_angle) == 0)
		return;
	if (data->player_pos.ray_angle >= convert_dgree(90) && data->player_pos.ray_angle <= convert_dgree(270))
		alpha_x = (floor((int)data->player_2d.x_2d / 40) * 40) - 0.001;
	else
		alpha_x = (floor((int)data->player_2d.x_2d / 40) * 40) + 40;

	alpha_y =  (alpha_x - data->player_2d.x_2d) * tan(data->player_pos.angle_in_radian);

	if (data->player_pos.ray_angle >= 0 && data->player_pos.ray_angle <= convert_dgree(180))
		alpha_y = data->player_2d.y_2d + fabs(alpha_y);
	else 
		alpha_y = data->player_2d.y_2d - fabs(alpha_y);
	
	if (data->player_pos.ray_angle >= convert_dgree(90) && data->player_pos.ray_angle <=  convert_dgree(270))
		xs = -40;
	else
		xs = 40;
		
	ys = xs * tan(data->player_pos.angle_in_radian);
	if (alpha_x < 0 || alpha_y < 0 || alpha_x > data->x_width || alpha_y > data->y_height)
	{
		data->player_2d.virtical_x2d_end = INT_MAX ;
		data->player_2d.virtical_y2d_end = INT_MAX;
		return;
	}
	if (data->map2d[(int)alpha_y / 40][(int)alpha_x /40] == '1')
	{
		data->player_2d.virtical_x2d_end = alpha_x;
		data->player_2d.virtical_y2d_end = alpha_y;
	}
	else
	{
		old_xs = xs + alpha_x;
		old_ys = alpha_y + ys;
		while (1)
		{
			if (old_xs < 0)
				old_xs = xs;
			if (old_ys < 0)
				old_ys = ys;
			if (old_xs > 0 && old_ys > 0 && old_xs < data->x_width && old_ys < data->y_height)
			{
				if (data->map2d[(int)old_ys / 40][(int)old_xs  / 40] != '1')
				{
					old_xs += xs;
					old_ys += ys;
				}
				else if (data->map2d[(int)old_ys  / 40][(int)old_xs / 40] == '1')
				{
					data->player_2d.virtical_x2d_end = old_xs;
					data->player_2d.virtical_y2d_end = old_ys;
					break;
				}
			}
			else
			{
				data->player_2d.virtical_x2d_end = INT_MAX;
				data->player_2d.virtical_y2d_end = INT_MAX;
				return;
			}
		}
	}
}