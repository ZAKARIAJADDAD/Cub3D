/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:59 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 15:06:19 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parsing/Libft/libft.h"
# include "parsing/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ROTATE_ANGLE 0.0872665
# define PLAYER_ANGLE 4.71239

# define X_WIDTH 1200
# define Y_HEIGHT 400
# define BROWN 0x00E0E0E0
# define BLACK 0x00000000
# define SKY 0x000080FF
# define GROUND 0x00A0A0A0
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define CYAN 0x0000FFFF
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define DARK_TURQUOISE 0x0000CED1
# define PI 3.14159265358979323846
# define PLAYER_SPEED 5
# define LINE_LENTH 30
# define GRIDE_SIZE 50
# define TEXTURE_SIZE 50

typedef struct t_2player
{
	int				map2d_x;
	int				map2d_y;
	double			distance;
	double			old_x;
	double			old_y;
	double			ray_angle;
	double			line_lenth;
	double			save_y_inc;
	double			save_x_inc;
	double			player_speed;
	double			line_x_start;
	double			line_y_start;
	double			player_x;
	double			player_y;
	double			horizontal_distance;
	double			virtical_distance;
	double			x_horizontal_line_end;
	double			y_horizontal_line_end;
	double			x_virtical_line_end;
	double			y_virtical_line_end;
	double			x_line_end;
	double			y_line_end;
	double			angle_in_radian;
}					t_2player;

typedef struct t_2map
{
	char			*key;
	char			*value;
	struct t_2map	*next;
}					t_2map;

typedef struct t_2tex
{
	double			x_wall_pos;
	double			y_wall_pos;
	double			texture_x;
	double			texture_y;
	void			*north_wall;
	char			*add;
	void			*east_wall;
	void			*west_wall;
	void			*south_wall;
	int				textuer_x_width;
	int				textuer_y_hight;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*texture_ptr;
	char			*buffer;

}					t_2tex;

typedef struct t_2img
{
	double			start;
	double 			steps;
	double 			y_inc;
	double			tex_increment;
	double			y_tex;
	float			y_increament;
	double			projected_slice_height;
	unsigned int	texture_color;

}					t_2img;

typedef	struct t_2vray
{
	double alpha_y;
	double alpha_x;
	double dy;
	double dx;
	double ys;
	double xs;
	double old_xs;
	double old_ys;
}		t_2vray;

typedef	struct t_2hray
{
	double alpha_y;
	double alpha_x;
	double dy;
	double dx;
	double ys;
	double xs;
	double old_xs;
	double old_ys;
}		t_2hray;

typedef struct t_2var
{
	double			x_screen;
	double			y_screen;
	int				x_width;
	int				y_height;
	t_2vray			vray_data;
	t_2hray			hray_data;
	t_2map			*map;
	t_2tex			textuer;
	t_2tex			textuer1;
	t_2tex			textuer2;
	t_2tex			textuer3;
	t_2img			dda_data;
	int				old_mouse_x;
	int				old_mouse_y;
	int				fd;
	int				i;
	int				j;
	int				count;
	char			**env2d;
	int				test;
	int				mouse_x;
	int				mouse_y;
	double			player_of_wall;
	double			distance_to_projection_plane;
	double			tmp_player_x;
	double			tmp_player_y;
	double			store_cos;
	double			store_sin;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_2player		player_pos;
	char			**tmp_arry;
	char			**tmp_arry2;
	void			*mlx;
	char			**map2d;
	char			*line_mp;
	void			*mlx_win;
	int				textures[TEXTURE_SIZE][TEXTURE_SIZE];
}					t_2var;




/*********************************************************************/
/*                                 Textuers                          */
/*********************************************************************/

void				textuers(double x, double y, t_2var *data);
void				load_texture(t_2var *data);
void				virtical_mapping(t_2var *data);
void				horizontal_mapping(t_2var *data);

void				my_mlx_pixel_put(t_2var *data, int x, int y, int color);


// player
void				player_map_position(t_2var *data);
void				player_direction(t_2var *data, char c);

/*********************************************************************/
/*                                 Movementes                        */
/*********************************************************************/

void				move_forward(t_2var *data);
void				move_back(t_2var *data);
void				move_right(t_2var *data);
void				move_left(t_2var *data);


/*********************************************************************/
/*                                 Rotitons	                         */
/*********************************************************************/


int					rander_map2d(t_2var *data);
void				rotate_left(t_2var *data);
void				rotate_right(t_2var *data);



void				draw_sky(t_2var *data, int x, int start, int end);
void				draw_line(t_2var *data, int x_pos);
void				horizotal_ray(t_2var *data);
void				virtical_ray(t_2var *data);

// rander map2d
void				clac_player_distence(t_2var *data);

// files of  view
void				player_view_filed(t_2var *data);

double				convert_dgree(int degree);

// filed of view ray cast
void				horizotal_ray(t_2var *data);
void				virtical_ray(t_2var *data);


// mouse movementes

void				left_side(t_2var *data);
void				right_side(t_2var *data);
int					move_mouse(t_2var *data);



// /minimap


void				destroy_fun(t_2var *data);
int					mouse_press(t_2var *data);
void				key_events(t_2var *data, int i);
int					move_player(int i, t_2var *data);
void				initialize_varibles(t_2var *data);
int					my_mlx_get_add(t_2var *data, int x, int y);
void				clac_projextion_distance(t_2var *data);
void				find_y_inc(t_2var *data, int x_pos);
void				fix_distortion(t_2var *data2);

void				vir_ray_protiction(t_2var *data);
int					vir_while_conditions(t_2var *dat2a);
int					vir_check_if_wall(t_2var *data);
int					vir_first_intersection(t_2var *data);
int					vir_find_first_point(t_2var	*data);
void				vir_ray_to_infinity(t_2var	*dat2a);
void				virtical_ray(t_2var	*data);
void				initlize_varibles(t_2var *data2);

void				hor_ray_protiction(t_2var *data);
int					hor_while_conditions(t_2var *dat2a);
int					hor_check_if_wall(t_2var *data);
int					hor_first_intersection(t_2var *data);
int					hor_find_first_point(t_2var	*data);
void				hor_ray_to_infinity(t_2var	*data);

/*********************************************************************/
/*                                 Parsing                           */
/*********************************************************************/

int					ft_error(char *s, int fd);
int					is_player(char c);
void				player_position(t_2var **dat2a);
void				check_map(t_2var **data);
void				check_colors(t_2map *map);
void				check_spaces(char *s);
void				check_file_path(t_2map *map);
void				map_process(t_2var **data, char *line);
void				ft_lstadd_back_s(t_2map **head, t_2map *new);
t_2map				*ft_lstnew_s(char *key, char *value);
t_2map				*ft_lstnew_s(char *key, char *valu2e);
void				load_texture(t_2var *data);
int					get_color_texture(t_2tex *tex, int i, int j, int s_wall);
void				get_image(t_2var *data, t_2tex *tex, char *path);
int					get_colors(t_2tex *tex, int x, int y);
int					get_pos(double pos, int w);
int					is_player(char c);
int					rest_of_map(char **line, t_2var **data);
void				fill_x_y_map(char *line, t_2var **data);
void				map_parsing(char *s, t_2var **data);


/*********************************************************************/
/*                                 Parsing                           */
/*********************************************************************/

#endif