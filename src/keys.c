#include "cub3d.h"

void	key_w_s(int keycode, t_all *all)
{
	if (keycode == W)
	{
		if ((int)all->map.map[(int)(all->vector.x_pos + all->vector.dir_x
				* all->vector.movespeed)][(int)(all->vector.y_pos)] - '0' == 0)
			all->vector.x_pos += all->vector.dir_x * all->vector.movespeed;
		if ((int)all->map.map[(int)(all->vector.x_pos)][(int)(all->vector.y_pos
				+ all->vector.dir_y * all->vector.movespeed)] - '0' == 0)
			all->vector.y_pos += all->vector.dir_y * all->vector.movespeed;
	}
	if (keycode == S)
	{
		if ((int)all->map.map[(int)(all->vector.x_pos - all->vector.dir_x
				* all->vector.movespeed)][(int)(all->vector.y_pos)] - '0' == 0)
			all->vector.x_pos -= all->vector.dir_x * all->vector.movespeed;
		if ((int)all->map.map[(int)(all->vector.x_pos)][(int)(all->vector.y_pos
				- all->vector.dir_y * all->vector.movespeed)] - '0' == 0)
			all->vector.y_pos -= all->vector.dir_y * all->vector.movespeed;
	}
}

void	key_d_a(int keycode, t_all *all)
{
	if (keycode == D)
	{
		if ((int)all->map.map[(int)(all->vector.x_pos + all->vector.plane_x
				* all->vector.movespeed)][(int)(all->vector.y_pos)] - '0' == 0)
			all->vector.x_pos += all->vector.plane_x * all->vector.movespeed;
		if ((int)all->map.map[(int)(all->vector.x_pos)][(int)(all->vector.y_pos
				+ all->vector.plane_y * all->vector.movespeed)] - '0' == 0)
			all->vector.y_pos += all->vector.plane_y * all->vector.movespeed;
	}
	if (keycode == A)
	{
		if ((int)all->map.map[(int)(all->vector.x_pos - all->vector.plane_x
				* all->vector.movespeed)][(int)(all->vector.y_pos)] - '0' == 0)
			all->vector.x_pos -= all->vector.plane_x * all->vector.movespeed;
		if ((int)all->map.map[(int)(all->vector.x_pos)][(int)(all->vector.y_pos
				- all->vector.plane_y * all->vector.movespeed)] - '0' == 0)
			all->vector.y_pos -= all->vector.plane_y * all->vector.movespeed;
	}
}

void	rotate(t_all *all, double rotspeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = all->vector.dir_x;
	all->vector.dir_x = all->vector.dir_x * cos(rotspeed)
		- all->vector.dir_y * sin(rotspeed);
	all->vector.dir_y = oldDirX * sin(rotspeed)
		+ all->vector.dir_y * cos(rotspeed);
	oldPlaneX = all->vector.plane_x;
	all->vector.plane_x = all->vector.plane_x * cos(rotspeed)
		- all->vector.plane_y * sin(rotspeed);
	all->vector.plane_y = oldPlaneX * sin(rotspeed)
		+ all->vector.plane_y * cos(rotspeed);
}

void	spawn_pos(t_all *all)
{
	if (all->map.map_dir == 'N')
		return ;
	else if (all->map.map_dir == 'E')
		rotate(all, 3 * M_PI / 2);
	else if (all->map.map_dir == 'S')
		rotate(all, M_PI);
	else if (all->map.map_dir == 'W')
		rotate(all, M_PI / 2);
}

int	key_pressed(int keycode, t_all *all)
{
	if (keycode == W || keycode == S)
		key_w_s(keycode, all);
	if (keycode == D || keycode == A)
		key_d_a(keycode, all);
	if (keycode == RIGHT)
		rotate(all, -all->vector.rotspeed);
	if (keycode == LEFT)
		rotate(all, all->vector.rotspeed);
	if (keycode == ESC)
		ft_close(all, 99);
	draw_dispay(all);
	return (0);
}
