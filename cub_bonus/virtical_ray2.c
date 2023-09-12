/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtical_ray2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:20:17 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/12 21:55:16 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	vir_ray_protiction(t_var *data)
{
	if (data->vray_data.old_xs < 0)
		data->vray_data.old_xs = data->vray_data.xs;
	if (data->vray_data.old_ys < 0)
		data->vray_data.old_ys = data->vray_data.ys;
}

int vir_while_conditions(t_var *data)
{
	vir_ray_protiction(data);
	if (data->vray_data.old_xs > 0 && data->vray_data.old_ys > 0 && \
	data->vray_data.old_xs < data->x_width && \
	data->vray_data.old_ys < data->y_height)
	{
		if (vir_check_if_wall(data) == 1)
			return (1);
	}
	else
	{
		vir_ray_to_infinity(data);
		return (1);
	}
	return (0);
}
