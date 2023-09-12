/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:38 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/12 20:34:27 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>
#include <limits.h>

void	destroy_fun()
{
	exit (3);
}

int	mouse_press(t_var *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}


void	find_y_inc(t_var *data, int x_pos)
{
	double 	wall_center;
	double 	start;
	double 		dx;
	double 		dy;
	
	wall_center = (data->y_screen / 2);
	data->dda_data.start = wall_center - (data->dda_data.projected_slice_height / 2);
	dx = x_pos;
	dy =  data->dda_data.projected_slice_height;
	data->dda_data.steps = fabs(dy);
	data->dda_data.y_inc = dy / data->dda_data.steps;
}

void	clac_projextion_distance(t_var *data)
{
	data->distance_to_projection_plane = tan(convert_dgree(30)) * ((int)data->x_screen/ 2);
}

void	draw_sky(t_var *data,int x, int start, int end)
{
	int i;
	int j;

	j = 0;
	while (j < start)
		my_mlx_pixel_put(data,x,j++,CYAN);
	i = start + end;
	while (i < data->y_screen)
		my_mlx_pixel_put(data,x,i++,GROUND);
}



int move_player(int i, t_var *data)
{
	data->tmp_player_x = data->player_pos.player_x;
	data->tmp_player_y = data->player_pos.player_y;
	if (i == 65307)
		destroy_fun();
	if (i == 119)
		move_forward(data);
	if (i == 115)
		move_back(data);
	if (i == 97)
		move_left(data);
	if (i == 100)
		move_right(data);
	if (i == 65363)
		rotate_right(data);
	if (i == 65361)
		rotate_left(data);

	if ((data->map2d[((int)data->tmp_player_y) / GRIDE_SIZE][((int)data->tmp_player_x) / GRIDE_SIZE] != '1')
	&& (data->map2d[(int)data->tmp_player_y / 50][(int)data->player_pos.player_x / 50] != '1' 
		&& data->map2d[(int)data->player_pos.player_y / 50][(int)data->tmp_player_x / 50] != '1'))
	{
			data->player_pos.player_y  =  data->tmp_player_y;
			data->player_pos.player_x  =  data->tmp_player_x;
	}

	return (0);
	
}

double	convert_dgree(int degree)
{
	return (degree * (PI / 180));
}

void	player_direction(t_var *data, char c)
{
	if (c == 'E')
		data->player_pos.angle_in_radian = convert_dgree(0);
	else if (c == 'S')
		data->player_pos.angle_in_radian = convert_dgree(90);
	else if (c == 'W')
		data->player_pos.angle_in_radian = convert_dgree(180);
	else if (c == 'N')
		data->player_pos.angle_in_radian = convert_dgree(270);
}

void	initlize_varibles(t_var *data)
{
	int i;
	i = 0;

	
 	data->map2d = data->env2d;
	while (data->map2d[i])
		i++;
	data->y_height = i * 50;
	data->player_pos.player_x = 0;
	data->player_pos.horizontal_distance = 0;
	data->player_pos.virtical_distance = 0;
	data->player_pos.player_y = 0;
	data->player_pos.player_speed = 3;
	data->player_pos.x_virtical_line_end = 0;
	data->player_pos.y_virtical_line_end = 0;
	data->player_pos.x_horizontal_line_end = 0;
	data->player_pos.y_horizontal_line_end = 0;
	data->player_pos.ray_angle = 0;
	data->player_pos.line_lenth = 0;
	data->store_cos = 0;
	data->store_sin = 0;
	data->tmp2d_player_x = 0;
	data->tmp2d_player_y = 0;
	data->mouse_x = data->x_screen / 2;
	data->mouse_y = data->y_screen / 2;
	data->x_screen = 1000;
	data->y_screen = 300;
	data->x_width = 33 * 50;
	data->old_mouse_x = 0;
	data->old_mouse_y = 0;

}




void	initlize_mlx(t_var *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->x_screen, data->y_screen, "map");
	data->img = mlx_new_image(data->mlx,data->x_screen ,data->y_screen );
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);	
}

void	raycasting(char **av, int ac)
{
	int fd;
	t_var *img;
	
	img = malloc(sizeof(t_var));
	map_parsing(av[1], &img);
	img->mlx = mlx_init();
	initlize_varibles(img);
	initlize_mlx(img);
	player_map_position(img);
	player_view_filed(img);
	load_texture(img);
	mlx_mouse_move(img->mlx ,img->mlx_win, img->x_screen / 2, img->y_screen / 2);
	mlx_mouse_hide(img->mlx, img->mlx_win);
	mlx_hook(img->mlx_win , 2, 1L<<0, &move_player, img);
	mlx_loop_hook(img->mlx, move_mouse, img);
	mlx_loop(img->mlx);
	free(img->mlx);
	free(img);
}

int main(int ac, char **av)
{
	if (ac == 2)
		raycasting(av, ac);
	else
		write(2, "Error: program requires two arguments!!\n", 40);
	return (0);
}