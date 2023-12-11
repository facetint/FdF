/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:20:49 by facetint          #+#    #+#             */
/*   Updated: 2023/12/07 16:37:50 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H

# define FDF_BONUS_H

# define HEIGHT	1024
# define WIDTH	1920
# define MENU_WIDTH	250

typedef enum s_projection
{
	ISO,
	PARALLEL
}		t_projection;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_coord_value
{
	struct s_coord_value	*next;
	int						z;
	int						color;
}				t_coord_value;

typedef struct s_map
{
	int	height;
	int	width;
	int	*coords_arr;
	int	*colors_arr;
	int	z_min;
	int	z_max;
}				t_map;

typedef struct s_camera
{
	double			x_angle;
	double			y_angle;
	double			z_angle;
	float			z_height;
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	int				x_offset;
	int				y_offset;
}				t_camera;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		z;
	int		prev_x;
	int		prev_y;
}			t_mouse;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				steep;
	t_camera		*camera;
	t_map			*map;
	t_mouse			*mouse;
	t_coord_value	*coords;
}				t_data;

void			draw(t_data *fdf);
void			draw_background(t_data *fdf);
void			ft_draw_line(t_point point1, t_point point2, t_data *fdf);
void			ft_draw_line_loop(t_point s, t_point e, float g, t_data *fdf);
t_point			new_point(int x, int y, t_map *map);
t_point			project(t_point p, t_data *fdf);
int				get_default_color(int z, t_map *map);
int				get_index(int x, int y, int width);
int				ft_get_color(int x, t_point p1, t_point p2, float ratio);
int				ft_lin_intpol(int first, int second, double p);

float			ft_abs(float n);
int				ft_r_int(float n);
float			ft_float(float n);
float			color_smoothing(float n);
void			ft_swap(int *a, int *b);

t_data			*fdf_init(t_coord_value **stack, t_map *map, int fd);
t_camera		*camera_init(t_data *fdf);
t_map			*map_init(int fd);

t_coord_value	*new_coord(char *coords_arr, t_data *fdf);
void			read_map(int fd, t_coord_value **coords, t_data *fdf);
int				ft_close_win(void *param);

int				is_hexa(char c);
int				ft_atoi_hex(char *str);
int				ft_atoi(const char *str);

int				key_press(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);

void			get_width(t_coord_value **coords,
					t_data *fdf, char **coords_arr);

void			free_map(t_data *fdf);
void			free_double(char **str);
void			free_map_coords(t_data *fdf, int a);
void			free_map_coords_(t_data *fdf);
void			fdf_init_(t_data *fdf);

void			convert(t_coord_value **coords_stack, t_data *fdf);
void			ft_add_front(t_coord_value **lst, t_coord_value *new);
t_coord_value	*ft_arr_last(t_coord_value **stack);

void			rotate_x(int *y, int *z, double x_angle);
void			rotate_y(int *y, int *z, double y_angle);
void			rotate_z(int *x, int *y, double z_angle);

void			isometric(int *x, int *y, int z);

void			ft_hook_controls(t_data *fdf);
void			zoom(int key, t_data *fdf);
void			rotate(int key, t_data *fdf);
void			pit(int key, t_data *fdf);
void			toggle_projection(int key, t_data *fdf);
void			ft_translate(int key, t_data *fdf);
void			menu_background(t_data *fdf);
char			**ft_split(char const *s, char c);

#endif
