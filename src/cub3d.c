/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 16:08:27 by nicky         #+#    #+#                 */
/*   Updated: 2022/10/16 16:06:36 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_img(t_all *all)
{
	all->img.mlx = mlx_init();
	// check_screen_size(all); // Deprecated in minilibx lib
	all->img.mlx_win = mlx_new_window(all->img.mlx, all->map.res_x,
			all->map.res_y, "cub3D");
	all->img.img = mlx_new_image(all->img.mlx, all->map.res_x, all->map.res_y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
	send_textures(all);
	spawn_pos(all);
	draw_screen(all);
}

void	ft_declare(t_all *all)
{
	all->vector.dir_x = -1;
	all->vector.dir_y = 0;
	all->vector.plane_x = 0;
	all->vector.plane_y = 0.66;
	all->ray.raydir_x = -1;
	all->ray.raydir_y = 0;
	all->vector.movespeed = 0.2;
	all->vector.rotspeed = 0.1;
	ft_init_img(all);
}

void	init(char *argv)
{
	t_all		all;

	parse_file(argv, &all);
	ft_declare(&all);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		init(argv[1]);
	else
		printf(RED "Error:\nInvalid arguments\nTry: ./cub3D path/to/map\n" RESET);
	return (0);
}
