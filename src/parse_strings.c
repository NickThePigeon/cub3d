/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_strings.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:17:55 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/31 16:35:27 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_res(t_all *all)
{
	char	**temp;
	int		i;

	i = 1;
	temp = ft_split(ft_strstr(all->map.file, "R "), '\n');
	if (!temp)
	{
		all->map.res_x = 720;
		all->map.res_y = 480;
		return ;
	}
	i = loop_ft_is(ft_isspace, i, temp[0]);
	if (!ft_isdigit(temp[0][i]))
		ft_close(all, 3);
	all->map.res_x = ft_atoi(&temp[0][i]);
	i = loop_ft_is(ft_isdigit, i, temp[0]);
	i = loop_ft_is(ft_isspace, i, temp[0]);
	if (!ft_isdigit(temp[0][i]))
		ft_close(all, 3);
	all->map.res_y = ft_atoi(&temp[0][i]);
	ft_freearr(temp);
}

char	*parse_path(t_all *all, char *needle)
{
	char	*temp;
	char	*ret;
	int		i;
	int		len;

	temp = ft_strstr(all->map.file, needle);
	if (!temp)
		ft_close(all, 2);
	i = 2;
	len = 0;
	while (ft_isspace(temp[i]))
		i++;
	while (!ft_isspace(temp[i + len]))
		len++;
	ret = ft_strduplen(&temp[i], len);
	return (ret);
}

int	parse_colors_loop(t_all *all, char **temp, int *color)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (j < 3)
	{
		i = loop_ft_is(ft_isspace, i, temp[0]);
		if (j > 0)
		{
			if (temp[0][i] != ',')
				ft_close(all, 4);
			i = loop_ft_is(ft_isspace, i + 1, temp[0]);
		}
		if (!ft_isdigit(temp[0][i]))
			ft_close(all, 4);
		color[j] = ft_atoi(&temp[0][i]);
		i = loop_ft_is(ft_isdigit, i, temp[0]);
		j++;
	}
	i = loop_ft_is(ft_isspace, i, temp[0]);
	return (i);
}

void	parse_colors(t_all *all, char *needle, int *color)
{
	char	**temp;
	int		i;

	temp = ft_split(ft_strstr(all->map.file, needle), '\n');
	if (!temp)
	{
		ft_freearr(temp);
		ft_close(all, 4);
	}
	i = parse_colors_loop(all, temp, color);
	if ((int)ft_strlen(temp[0]) > i)
	{
		ft_freearr(temp);
		ft_close(all, 4);
	}
	ft_freearr(temp);
}
