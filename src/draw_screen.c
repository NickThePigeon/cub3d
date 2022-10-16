/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:11:35 by nicky         #+#    #+#                 */
/*   Updated: 2022/10/16 13:06:57 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_all *all)
{
	t_img	wall_img;
	int		i;

	i = 0;
	while (i < all->map.res_x)
	{
		init_raycast(all, i);
		raycast_one(all);
		raycast_two(all);
		raycast_three(all);
		wall_img = check_tex_side(wall_img, all);
		ray_tex(wall_img, all);
		put_tex(wall_img, all, i);
		i++;
	}
	// mlx_put_image_to_window(all->img.mlx, all->img.mlx_win, all->img.img, 0, 0);
	mlx_image_to_window(all->img.mlx_ptr, all->img.img_ptr, 0, 0);
}

void	draw_dispay(t_all *all)
{
	all->img.color = all->map.cl_color;
	fill_rect(all, 0, 0, all->map.res_y / 2);
	all->img.color = all->map.fl_color;
	fill_rect(all, 0, all->map.res_y / 2, all->map.res_y / 2);
	draw_wall(all);
}

void	draw_screen(t_all *all)
{
	draw_dispay(all);
	// mlx_hook(all->img.mlx_win, KEY_PRESS, 0, key_pressed, all);
	// mlx_hook(all->img.mlx_win, DESTROY_NOTIFY, 0, ft_close, all);
	// mlx_loop(all->img.mlx);
	mlx_loop(all->img.mlx_ptr);
}
