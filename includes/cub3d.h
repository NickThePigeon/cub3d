/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 16:08:42 by nicky         #+#    #+#                 */
/*   Updated: 2022/10/16 12:57:51 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define	LEFT 123
# define	RIGHT 124
# define	W 13
# define	S 1
# define	A 0
# define	D 2
# define	ESC 53
# define	RED "\x1B[31m"
# define	GREEN "\033[32m"
# define	RESET "\x1B[0m"
# define	DESTROY_NOTIFY 17
# define	KEY_PRESS 2

# include "../libft/libft.h"
# include	"../MLX42/include/MLX42/MLX42.h"
# include	<stdio.h>
# include	<math.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>

typedef struct s_img
{
	mlx_t		*mlx_ptr;
	mlx_image_t *img_ptr;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	int			color;
}				t_img;

typedef struct s_map
{
	char			*file;
	char			map_dir;
	int				res_y;
	int				res_x;
	int				map_y;
	int				map_x;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				fl_rgb[3];
	int				cl_rgb[3];
	unsigned int	fl_color;
	unsigned int	cl_color;
	char			**map;
}				t_map;

typedef struct s_vector
{
	double		y_pos;
	double		x_pos;
	double		camera_x;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	double		movespeed;
	double		rotspeed;
}				t_vector;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	double		x_tex;
	double		y_tex;
	double		wallX;
	double		y_tex_step;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_ray;

typedef struct s_texture
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}				t_texture;

typedef struct s_all
{
	t_img		img;
	t_map		map;
	t_vector	vector;
	t_ray		ray;
	t_texture	texture;
}				t_all;

void	parse_file(char *argv, t_all *all);
void	get_map_axes(t_all *all);
void	error_strings(int err);
void	parse_vars(t_all *all);
void	find_map_pos(t_all *all);
void	free_on_exit(t_all *all, int err);
int		key_pressed(int keycode, t_all *all);
void	check_begin_end(t_all *all);

void	spawn_pos(t_all *all);
void	check_valid_map(t_all *all);
void	parse_map(t_all *all);
void	parse_colors(t_all *all, char *needle, int *color);
int		parse_colors_loop(t_all *all, char **temp, int *color);
void	parse_res(t_all *all);
char	*parse_path(t_all *all, char *needle);

int		ft_close(t_all *all, int err);
void	error_strings(int err);
void	error_strings_2(int err);
int		ft_namecheck(char *str, char *name);
void	draw_dispay(t_all *all);
void	draw_screen(t_all *all);

int		is_notmap(char c);
int		notmap_func(char **array, int i, int j);
int		compare_set(char c, char *valid);
int		zero_or_one(char *str);
void	check_file(t_all *all);

void	convert_color(t_all *all);

void	init_raycast(t_all *all, int i);
void	ray_tex(t_img wall_img, t_all *all);
void	raycast_one(t_all *all);
void	raycast_two(t_all *all);
void	raycast_three(t_all *all);

void	draw_wall(t_all *all);
void	draw_dispay(t_all *all);
void	draw_screen(t_all *all);

void	send_textures(t_all *all);
int		get_xpm_texture(t_img *img, char *file);
t_img	check_tex_side(t_img wall_img, t_all *all);
void	put_tex(t_img wall_img, t_all *all, int i);

void	ft_init_img(t_all *all);
void	ft_declare(t_all *all);
void	check_screen_size(t_all *all);
void	init(char *argv);

void	my_mlx_pixel_put(t_all *all, int x, int y);
void	put_horizontal(t_all *all, int x, int y, int len);
void	put_vertical(t_all *all, int x, int y, int len);
void	fill_rect(t_all *all, int x, int y, int ylen);

#endif