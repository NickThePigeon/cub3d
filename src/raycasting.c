/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:06:57 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/13 17:25:45 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_all *all, int i)
{
	all->vector.camera_x = 2 * i / (double)all->map.res_x - 1;
	all->ray.raydir_x = all->vector.dir_x + all->vector.plane_x
		* all->vector.camera_x;
	all->ray.raydir_y = all->vector.dir_y + all->vector.plane_y
		* all->vector.camera_x;
	all->ray.mapx = all->vector.x_pos;
	all->ray.mapy = all->vector.y_pos;
	all->vector.deltadist_x = fabs(1 / all->ray.raydir_x);
	all->vector.deltadist_y = fabs(1 / all->ray.raydir_y);
	all->ray.hit = 0;
}

void	raycast_one(t_all *all)
{
	if (all->ray.raydir_x < 0)
	{
		all->ray.stepx = -1;
		all->vector.sidedist_x = (all->vector.x_pos - all->ray.mapx)
			* all->vector.deltadist_x;
	}
	else
	{
		all->ray.stepx = 1;
		all->vector.sidedist_x = (all->ray.mapx + 1.0 - all->vector.x_pos)
			* all->vector.deltadist_x;
	}
	if (all->ray.raydir_y < 0)
	{
		all->ray.stepy = -1;
		all->vector.sidedist_y = (all->vector.y_pos - all->ray.mapy)
			* all->vector.deltadist_y;
	}
	else
	{
		all->ray.stepy = 1;
		all->vector.sidedist_y = (all->ray.mapy + 1.0 - all->vector.y_pos)
			* all->vector.deltadist_y;
	}
}

void	raycast_two(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->vector.sidedist_x < all->vector.sidedist_y)
		{
			all->vector.sidedist_x += all->vector.deltadist_x;
			all->ray.mapx += all->ray.stepx;
			all->ray.side = 0;
		}
		else
		{
			all->vector.sidedist_y += all->vector.deltadist_y;
			all->ray.mapy += all->ray.stepy;
			all->ray.side = 1;
		}
		if ((all->map.map[all->ray.mapx][all->ray.mapy] - '0') > 0)
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		all->vector.perpwalldist = (all->ray.mapx - all->vector.x_pos
				+ (1 - all->ray.stepx) / 2) / all->ray.raydir_x;
	else
		all->vector.perpwalldist = (all->ray.mapy - all->vector.y_pos
				+ (1 - all->ray.stepy) / 2) / all->ray.raydir_y;
}

void	raycast_three(t_all *all)
{
	all->ray.lineheight = (int)(all->map.res_y / all->vector.perpwalldist);
	all->ray.drawstart = -all->ray.lineheight / 2 + all->map.res_y / 2;
	if (all->ray.drawstart < 0)
		all->ray.drawstart = 0;
	all->ray.drawend = all->ray.lineheight / 2 + all->map.res_y / 2;
	if (all->ray.drawend >= all->map.res_y)
		all->ray.drawend = all->map.res_y - 1;
}

void	ray_tex(t_img wall_img, t_all *all)
{
	if (all->ray.side == 0)
		all->ray.wallX = all->vector.y_pos + all->vector.perpwalldist
			* all->ray.raydir_y;
	else
		all->ray.wallX = all->vector.x_pos + all->vector.perpwalldist
			* all->ray.raydir_x;
	all->ray.wallX -= floor((all->ray.wallX));
	all->ray.x_tex = (all->ray.wallX * (double)wall_img.width);
	if ((all->ray.side == 0 && all->ray.raydir_x > 0)
		|| (all->ray.side == 1 && all->ray.raydir_y < 0))
		all->ray.x_tex = wall_img.width - all->ray.x_tex;
	all->ray.y_tex = 0;
	all->ray.y_tex_step = (double)wall_img.height / (double)all->ray.lineheight;
	if (all->ray.lineheight > all->map.res_y)
		all->ray.y_tex = (double)(all->ray.lineheight
				- all->map.res_y)*all->ray.y_tex_step / 2;
}
