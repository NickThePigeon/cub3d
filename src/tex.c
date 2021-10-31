/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:13:36 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/17 10:14:22 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_xpm_texture(t_img *img, char *file)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return (-1);
	img->img = mlx_xpm_file_to_image(img->mlx, file, &img->width, &img->height);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		return (-1);
	return (1);
}

void	send_textures(t_all *all)
{
	int	err;

	err = 1;
	err = get_xpm_texture(&all->texture.no, all->map.no);
	if (err < 0)
		ft_close(all, 12);
	err = get_xpm_texture(&all->texture.so, all->map.so);
	if (err < 0)
		ft_close(all, 12);
	err = get_xpm_texture(&all->texture.we, all->map.we);
	if (err < 0)
		ft_close(all, 12);
	err = get_xpm_texture(&all->texture.ea, all->map.ea);
	if (err < 0)
		ft_close(all, 12);
}

t_img	check_tex_side(t_img wall_img, t_all *all)
{
	if (all->ray.raydir_y < 0 && all->ray.side == 1)
		wall_img = all->texture.we;
	else if (all->ray.raydir_y > 0 && all->ray.side == 1)
		wall_img = all->texture.ea;
	else if (all->ray.raydir_x > 0 && all->ray.side == 0)
		wall_img = all->texture.so;
	else if (all->ray.raydir_x < 0 && all->ray.side == 0)
		wall_img = all->texture.no;
	return (wall_img);
}
