

#include "cub3d_bonus.h"

void	hor_ray_protiction(t_var *data)
{
    if (data->hray_data.old_xs < 0)
        data->hray_data.old_xs = data->hray_data.xs;
    if (data->hray_data.old_ys < 0)
        data->hray_data.old_ys = data->hray_data.ys;
}

int	hor_while_conditions(t_var *data)
{
	hor_ray_protiction(data);
    if (data->hray_data.old_xs > 0 && data->hray_data.old_ys > 0 \
    && data->hray_data.old_xs < data->x_width && \
    data->hray_data.old_ys < data->y_height)
	{
		if (hor_check_if_wall(data) == 1)
			return (1);
	}
	else
	{
		hor_ray_to_infinity(data);
		return (1);
	}
	return (0);
}