/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:15:08 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/18 14:06:42 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_screen_size(t_all *all)
{
	int	x;
	int	y;
	int	print;

	print = 0;
	mlx_get_screen_size(all->img.mlx, &x, &y);
	if (all->map.res_x > x)
	{
		all->map.res_x = x;
		print = 1;
	}
	if (all->map.res_y > y)
	{
		all->map.res_y = y;
		print = 1;
	}
	if (print == 1)
		printf(GREEN
			"File Resolution to big, adjusted to screen resolution\n" RESET);
}

int	zero_or_one(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 1;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
			&& ft_isspace(str[i]) == 0)
			ret = 0;
		i++;
	}
	return (ret);
}

int	is_notmap(char c)
{
	if (!c)
		return (1);
	if (ft_isspace(c) || c == '\n')
		return (1);
	else
		return (0);
}

int	compare_set(char c, char *valid)
{
	int	i;

	i = 0;
	while (valid[i] != '\0')
	{
		if (valid[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_file(t_all *all)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_split(all->map.file, '\n');
	while (array[i])
		i++;
	ft_freearr(array);
	if (i == (all->map.map_y + 8))
		ft_close(all, 6);
}
