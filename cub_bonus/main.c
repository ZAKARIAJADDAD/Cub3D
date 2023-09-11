/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:38 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/11 13:21:10 by zael-wad         ###   ########.fr       */
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

int	my_mlx_get_add(t_var *data, int x, int y)
{
	char	*dst;
	
	dst = data->textuer.add + (y * data->textuer.line_length + x * (data->textuer.bits_per_pixel / 8));
	return(*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;
	if (x > 0 && y > 0 && x < data->x_screen && y < data->y_screen)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
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

void	draw_line(t_var *data, int x_pos)
{
	int 		i;
	int 		stps;
	
	i = 0;
	data->dda_data.y_increament = 0;
	
	virtical_ray(data);
	horizotal_ray(data);
	clac_player_distence(data);
	fix_distortion(data);
	find_y_inc(data, x_pos);
	draw_sky(data, x_pos , data->dda_data.start, data->dda_data.projected_slice_height);
	
	if (data->textuer.textuer_y_hight > data->dda_data.projected_slice_height)
		stps = data->textuer.textuer_y_hight  / data->dda_data.projected_slice_height;
	else
		stps = data->dda_data.projected_slice_height /  data->textuer.textuer_y_hight;
	while (i <= data->dda_data.steps)
	{
		data->dda_data.texture_color = 0;
		if (data->player_pos.virtical_distance  < data->player_pos.horizontal_distance)
        	virtical_mapping(data);
		else
        	horizontal_mapping(data);
		data->dda_data.y_increament += data->dda_data.y_tex;
		my_mlx_pixel_put(data, x_pos, data->dda_data.start, data->dda_data.texture_color);
		data->dda_data.start++;
		i++;
	}
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

void	rander_minimap(t_var *img)
{
	img->player_pos.map2d_y = 0;
	while (img->map2d[img->player_pos.map2d_y])
	{
		img->player_pos.map2d_x = 0;
		while (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x])
		{
			if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ] == '1')
				fill_wall(img,(img->player_pos.map2d_y + 1) * 40,  (img->player_pos.map2d_x  + 1) * 40);
			else if (img->map2d[img->player_pos.map2d_y][img->player_pos.map2d_x ] != '1')
				fill_ground(img,  (img->player_pos.map2d_y + 1) * 40, (img->player_pos.map2d_x + 1) * 40);
			img->player_pos.map2d_x++;
		}
		img->player_pos.map2d_y++;
	}
	my_mlx_pixel_put(img, img->player_2d.x_2d, img->player_2d.y_2d, BLACK);
}

void	player_view_filed(t_var *data)
{
	int i;
	double steps;

	i = 0;
	clac_projextion_distance(data);
	data->player_pos.ray_angle = data->player_pos.angle_in_radian;
	steps = convert_dgree(60) / data->x_screen;
	while (i < data->x_screen / 2)
	{
		data->player_pos.ray_angle -= steps;
		if (data->player_pos.ray_angle < 0)
			data->player_pos.ray_angle = 2 * PI;
		i++;
	}
	i = 0;
	while (i < data->x_screen)
	{
		if (data->player_pos.ray_angle > 2 * PI)
			data->player_pos.ray_angle = 0;
		data->player_pos.ray_angle += steps;
		draw_line(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
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
 	data->map2d = data->env2d;
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
	data->x_width = x_width(data->map2d);
	data->y_height = y_height(data->map2d);
	data->x_screen = 1000;
	data->y_screen = 300;
	data->old_mouse_x = 0;
	data->old_mouse_y = 0;

}


void	mini_map(t_var *data)
{
	int i;
	int k;
	int player_posx;
	int player_posy;
	int x_pos;
	int y_pos;

	i = 0;
	x_pos = data->player_pos.player_x - 100;
	y_pos = data->player_pos.player_y - 100;
	// printf("%d\n",(int)x_pos);
	// printf("%d\n",(int)y_pos);
	while (i <= 100)
	{
		k = 0;
		x_pos =data->player_pos.player_x - 50;
		while (k <= 100)
		{
			
			if (x_pos == data->player_pos.player_x && y_pos == data->player_pos.player_y)
				my_mlx_pixel_put(data, k, i, BLACK);
			if (data->map2d[y_pos / 50][x_pos / 50] == '1')
				my_mlx_pixel_put(data, k, i, GROUND);
			else if (data->map2d[y_pos / 50 ][x_pos / 50] != '1')
				my_mlx_pixel_put(data, k, i, DARK_TURQUOISE);
			x_pos++;
			k++;
			
		}
		y_pos++;
		i++;
	}
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