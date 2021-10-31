/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 14:07:09 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/31 14:03:46 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map(t_all *all, int len, int i, char **array)
{
	all->map.map = ft_calloc(len + 1, sizeof(char *));
	if (!all->map.map)
		ft_close(all, 7);
	while (len > 0)
	{
		all->map.map[len - 1] = ft_strdup(array[i + len - 1]);
		len--;
	}
}

void	parse_map(t_all *all)
{
	char	**array;
	int		val;
	int		i;
	int		len;

	array = ft_split(all->map.file, '\n');
	val = 1;
	len = 0;
	i = ft_arrlen(array);
	while (val > 0)
	{
		val = zero_or_one(array[i - 1]);
		if (val > 0)
		{
			len++;
			i--;
		}
	}
	fill_map(all, len, i, array);
	ft_freearr(array);
}

/* find map pos and put direction char in map.map_dir */

static int	set_pos(t_all *all, int i, int j, int valid)
{
	all->vector.y_pos = (double)j + 0.5;
	all->vector.x_pos = (double)i + 0.5;
	all->map.map_dir = all->map.map[i][j];
	all->map.map[i][j] = '0';
	if (valid == 1)
		ft_close(all, 9);
	valid = 1;
	return (valid);
}

void	find_map_pos(t_all *all)
{
	int	i;
	int	j;
	int	valid;

	valid = 0;
	i = 0;
	while (i < all->map.map_y)
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (all->map.map[i][j] == 'N' || all->map.map[i][j] == 'E'
				|| all->map.map[i][j] == 'S' || all->map.map[i][j] == 'W')
			{
				valid = set_pos(all, i, j, valid);
			}
			j++;
		}
		i++;
	}
	if (valid == 0)
		ft_close(all, 10);
}

void	check_begin_end(t_all *all)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < all->map.map_y)
	{
		len = ft_strlen(all->map.map[i]);
		if (i == 0 || i + 1 == all->map.map_y)
		{
			j = 0;
			while (j < len - 1)
			{
				if (all->map.map[i][j] == '0')
					ft_close(all, 8);
				j++;
			}
		}
		if (all->map.map[i][0] == '0' || all->map.map[i][len - 1] == '0')
			ft_close(all, 8);
		i++;
	}
}
