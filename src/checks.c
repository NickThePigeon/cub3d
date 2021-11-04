/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:19:36 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/04 12:20:25 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_color(t_all *all)
{
	if (all->map.fl_rgb[0] < 0 || all->map.fl_rgb[0] > 255
		|| all->map.fl_rgb[1] < 0 || all->map.fl_rgb[1] > 255
		|| all->map.fl_rgb[2] < 0 || all->map.fl_rgb[2] > 255
		|| all->map.cl_rgb[0] < 0 || all->map.cl_rgb[0] > 255
		|| all->map.cl_rgb[1] < 0 || all->map.cl_rgb[1] > 255
		|| all->map.cl_rgb[2] < 0 || all->map.cl_rgb[2] > 255)
	{
		ft_close(all, 5);
	}
	all->map.fl_color = all->map.fl_rgb[0] * 256 * 256
		+ all->map.fl_rgb[1] * 256 + all->map.fl_rgb[2];
	all->map.cl_color = all->map.cl_rgb[0] * 256 * 256
		+ all->map.cl_rgb[1] * 256 + all->map.cl_rgb[2];
}

int	notmap_func(char **array, int i, int j)
{
	if ((compare_set(array[i][j], "0NSEW"))
		&& (is_notmap(array[i - 1][j])
		|| is_notmap(array[i + 1][j])
		|| is_notmap(array[i][j - 1])
		|| is_notmap(array[i][j + 1])
		|| is_notmap(array[i - 1][j - 1])
		|| is_notmap(array[i + 1][j + 1])
		|| is_notmap(array[i - 1][j + 1])
		|| is_notmap(array[i + 1][j - 1])))
	{
		return (1);
	}
	else
		return (0);
}

void	check_valid_map(t_all *all)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < all->map.map_y - 1)
	{
		j = 1;
		len = ft_strlen(all->map.map[i]);
		while (j < len - 1)
		{
			if (notmap_func(all->map.map, i, j))
				ft_close(all, 8);
			j++;
		}
		i++;
	}
	check_begin_end(all);
}
