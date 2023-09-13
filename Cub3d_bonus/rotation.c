/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:19:16 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/12 20:27:10 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_left(t_var	*data)
{
	data->player_pos.angle_in_radian -= ROTATE_ANGLE;
	if (data->player_pos.angle_in_radian < 0)
		data->player_pos.angle_in_radian = 2 * PI;
}

void	rotate_right(t_var	*data)
{
	data->player_pos.angle_in_radian += ROTATE_ANGLE;
	if (data->player_pos.angle_in_radian > 2 * PI)
		data->player_pos.angle_in_radian = 0;
}
