/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:21:10 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/31 16:24:55 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_axes(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	all->map.map_y = 0;
	all->map.map_x = 0;
	while (all->map.map[y])
	{
		x = ft_strlen(all->map.map[y]);
		if (x > all->map.map_x)
			all->map.map_x = x;
		y++;
	}
	all->map.map_y = y;
}

void	parse_file(char *filename, t_all *all)
{
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".cub", 3) != 0)
		ft_close(all, 0);
	if (!read_to_eof(filename, &all->map.file))
		ft_close(all, 1);
	parse_res(all);
	all->map.no = parse_path(all, "NO ");
	all->map.so = parse_path(all, "SO ");
	all->map.we = parse_path(all, "WE ");
	all->map.ea = parse_path(all, "EA ");
	parse_colors(all, "F ", all->map.fl_rgb);
	parse_colors(all, "C ", all->map.cl_rgb);
	parse_map(all);
	convert_color(all);
	get_map_axes(all);
	check_map_vars(all);
	check_valid_map(all);
	find_map_pos(all);
	check_file(all);
}
