/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:38 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/26 23:36:38 by zael-wad         ###   ########.fr       */
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

void	fix_distortion(t_var *data)
{
	data->player_pos.distance = data->player_pos.distance * cos(data->player_pos.ray_angle);
}

void	draw_line(t_var *data, int x_pos)
{
	int 		x;
	int 		y;
	double 		dx;
	double 		dy;
	double 		step;
	double 		x_inc;
	double 		y_inc;
	double		x_nearest;
	double		y_nearest;
	int i;

	double Projected_Slice_Height;
	double wall_center;
	double hight;
	double start;
	int color;
	int stps;
	virtical_ray(data);
	horizotal_ray(data);
	clac_player_distence(data);
	if (data->player_pos.ray_angle < data->player_pos.angle_in_radian)
		data->player_pos.distance = data->player_pos.distance * cos((data->player_pos.ray_angle - data->player_pos.angle_in_radian));
	else 
		data->player_pos.distance = data->player_pos.distance * cos((data->player_pos.angle_in_radian - data->player_pos.ray_angle));

	Projected_Slice_Height = GRIDE_SIZE / data->player_pos.distance * data->distance_to_projection_plane;
	
	if (Projected_Slice_Height < 0)
		Projected_Slice_Height = 0;
	if (Projected_Slice_Height > data->y_screen)
		Projected_Slice_Height = data->y_screen;
	
	wall_center = (data->y_screen / 2);
	start = wall_center - (Projected_Slice_Height / 2);
	dx = x_pos;
	dy =  Projected_Slice_Height;
	step = fabs(dy);
	y_inc = dy / step;
	i =0;

	if (data->textuer.textuer_y_hight > Projected_Slice_Height)
		stps = data->textuer.textuer_y_hight  / Projected_Slice_Height;
	else
		stps = Projected_Slice_Height /  data->textuer.textuer_y_hight;
	
	double tex_inc;
	while (i <= step)
	{
		// while (stps != 0)
		textuers(data->player_pos.x_line_end, data->player_pos.y_line_end, data);
		if (data->textuer.textuer_x_width > Projected_Slice_Height)
		{
			tex_inc =  data->textuer.textuer_y_hight / Projected_Slice_Height;
		}
		else 
			tex_inc = Projected_Slice_Height / data->textuer.textuer_y_hight;
		// if ()
		color =  my_mlx_get_add(data, data->textuer.texture_x, data->textuer.texture_y +  tex_inc);
		if (data->player_pos.pd < data->player_pos.pe)
		{
			
			my_mlx_pixel_put(data, x_pos, (int)start ,RED);
		}
		else 
			my_mlx_pixel_put(data, x_pos, (int)start , WHITE);
		start += y_inc;
		i++;
	}
}

void	ray_draw(t_var *data)
{
	int x;
	int y;
	double dx;
	double dy;
	double step;
	double x_inc;
	double y_inc;
	double	x_nearest;
	double	y_nearest;
	int i;
	
	double x_start;
	double y_start;
	i = 0;

	horizontal_2d(data);
	virtical_2d(data);
	clac_2dplayer_distence(data);
	x_start = data->player_2d.x_2d;
	y_start = data->player_2d.y_2d;
	dx = data->player_2d.calc_xend - x_start;
	dy = data->player_2d.calc_yend - y_start;
	
	
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	x_inc = dx / step;
	y_inc = dy / step;

	while (i <= step)
	{
		if (data->player_2d.calc_xend > 0 && data->player_2d.calc_yend  > 0)
		{
			if (data->map2d[(int)y_start/ 40][(int)x_start / 40] != '1')
			{
				my_mlx_pixel_put(data, (int)x_start, (int)y_start ,RED);
				x_start += x_inc;
				y_start += y_inc;
			}
			i++;
		}
		
	}
}

void	clac_projextion_distance(t_var *data)
{
	data->distance_to_projection_plane = tan(convert_dgree(30)) * ((int)data->x_screen/ 2);
}

void	draw_sky(t_var *data)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while (i < data->x_screen)
	{
		j = 0;
		while (j < data->y_screen)
		{
			if (j < (data->y_screen/ 2))
				my_mlx_pixel_put(data,i,j,CYAN);
			else
				my_mlx_pixel_put(data,i,j,GROUND);
			j++;
		}
		i++;
	}	
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
	int i;

	my_mlx_pixel_put(img, img->player_2d.x_2d, img->player_2d.y_2d, BLACK);
}

void	player_view_filed(t_var *data)
{

	double tmp;
	double start;
	double end;
	double steps;
	int i;
	i = 0;
	clac_projextion_distance(data);
	draw_sky(data);
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
	data->tmp2d_player_x = data->player_2d.x_2d;
	data->tmp2d_player_y = data->player_2d.y_2d;

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

	if (data->map2d[((int)data->tmp_player_y) / GRIDE_SIZE][((int)data->tmp_player_x) / GRIDE_SIZE] != '1')
	{
		data->player_pos.player_y  =  data->tmp_player_y;
		data->player_pos.player_x  =  data->tmp_player_x;
		data->player_2d.x_2d  = data->tmp2d_player_x ;
		data->player_2d.y_2d = data->tmp2d_player_y ;
	}
	return (0);
	
}

double	convert_dgree(int degree)
{
	return (degree * (PI / 180));
}

// void	player_direction_facing(t_var *data)
// {
// 	if (data->)
// }
void	initlize_varibles(t_var *data)
{
	// player_direction_facing(data);
	data->player_pos.player_x = 0;
	data->player_pos.pd = 0;
	data->player_pos.pe = 0;
	data->player_pos.player_y = 0;
	data->player_pos.player_speed = 3;
	data->player_pos.angle_in_radian = convert_dgree(90);
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
}

// void	player_2dpos(t_var *data)
// {
// 	data->player_pos.map2d_y = 0;
// 	while (data->map2d[data->player_pos.map2d_y])
// 	{
// 		data->player_pos.map2d_x = 0;
// 		while (data->map2d[data->player_pos.map2d_y][data->player_pos.map2d_x])
// 		{
// 			if (data->map2d[data->player_pos.map2d_y][data->player_pos.map2d_x] == 'P')
// 			{
// 				data->player_2d.x_2d = ((data->player_pos.map2d_x + 1) * 40) - 20;
// 				data->player_2d.y_2d = ((data->player_pos.map2d_y + 1) * 40) - 20;
// 			}
// 			data->player_pos.map2d_x++;
// 		}
// 		data->player_pos.map2d_y++;
// 	}
// }

void	textuers(double x, double y, t_var *data)
{
	data->textuer.x_wall_pos = (int)x % GRIDE_SIZE;
	data->textuer.y_wall_pos = (int)y % GRIDE_SIZE;
	data->textuer.texture_x = (data->textuer.x_wall_pos * 100) / GRIDE_SIZE;
	data->textuer.texture_y = (data->textuer.y_wall_pos * 100) / GRIDE_SIZE;

}

void	mini_map(t_var *img)
{
	int i;
	int k;
	int player_posx;
	int player_posy;
	int x_pos;
	int y_pos;

	i = 1;
	x_pos = img->player_pos.player_x / 50;
	y_pos = img->player_pos.player_y / 50;
	player_posy = y_pos - 1;
	while (i <= 4)
	{
		k = 2;
		player_posx = x_pos - 1;
		while (k <= 6)
		{
			if (img->map2d[player_posy][player_posx] == '1')
				fill_wall(img, (i + 1) * 20,  (k + 1) * 20);
			if (img->map2d[player_posy][player_posx] != '1')
				fill_ground(img, (i + 1) * 20,  (k + 1) * 20);
			// if (img->map2d[player_posy][player_posx] == 'P')
				// my_mlx_pixel_put(img, img->player_2d.x_2d ,img->player_2d.y_2d , BLACK);
			player_posx++;
			k++;
		}
		player_posy++;
		i++;
	}
				player_fil(img, (x_pos) * 20,  (y_pos) * 20);
}

void	raycasting(char **av, int ac)
{
	int fd;
    t_var *img;

	img = malloc(sizeof(t_var));
	map_parsing(av[1], &img);
	img->mlx = mlx_init();
 	img->map2d = img->env2d;
	initlize_varibles(img);
	img->x_screen = 1000;
	img->y_screen = 300;
	img->mlx_win = mlx_new_window(img->mlx, img->x_screen,img->y_screen, "map");
	img->img = mlx_new_image(img->mlx,img->x_screen ,img->y_screen );
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);	
	img->xpm_img.ptr3 = mlx_xpm_file_to_image(img->mlx , "xpm_file/sm.xpm", &img->xpm_img.width , &img->xpm_img.hight);
	img->textuer.north_wall = mlx_xpm_file_to_image(img->mlx, "xpm_file/wall.xpm", 
		&img->textuer.textuer_x_width , &img->textuer.textuer_y_hight);
	img->textuer.add = mlx_get_data_addr(img->textuer.north_wall , &img->textuer.bits_per_pixel,
		&img->textuer.line_length, &img->textuer.endian);	

	player_map_position(img);
	player_view_filed(img);
	// clac_projextion_distance(&img);
	mlx_mouse_move(img->mlx ,img->mlx_win, img->x_screen / 2, img->y_screen / 2);
	mlx_mouse_hide(img->mlx, img->mlx_win);
	mlx_hook(img->mlx_win , 2, 1L<<0, &move_player, img);
	mlx_loop_hook(img->mlx, move_mouse, img);
	mlx_loop(img->mlx);
}

int main(int ac, char **av)
{
	if (ac == 2)
		raycasting(av, ac);
	else
		write(2, "Error: program requires two arguments!!\n", 40);
	// free(data);
	return (0);
}