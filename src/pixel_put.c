/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_put.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 15:42:45 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/18 16:32:22 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y)
{
	char	*dst;

	dst = all->img.addr + (y * all->img.line_length
			+ x * (all->img.bits_per_pixel / 8));
	*(unsigned int *)dst = all->img.color;
}

void	put_horizontal(t_all *all, int x, int y, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_mlx_pixel_put(all, x + i, y);
		i++;
	}
}

void	put_vertical(t_all *all, int x, int y, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_mlx_pixel_put(all, x, y + i);
		i++;
	}
}

void	fill_rect(t_all *all, int x, int y, int ylen)
{
	int	i;

	i = 0;
	while (i < ylen)
	{
		put_horizontal(all, x, y + i, all->map.res_x);
		i++;
	}
}

void	put_tex(t_img wall_img, t_all *all, int i)
{
	char	*dst;
	int		y_start;
	int		y_end;

	y_start = all->ray.drawstart;
	y_end = all->ray.drawend;
	while (y_start <= y_end)
	{
		dst = wall_img.addr + ((int)(all->ray.y_tex) % wall_img.height
				* wall_img.line_length + (int)all->ray.x_tex % wall_img.width
				* (wall_img.bits_per_pixel / 8));
		all->img.color = *(unsigned int *)dst;
		my_mlx_pixel_put(all, i, y_start);
		all->ray.y_tex += all->ray.y_tex_step;
		y_start++;
	}
}
