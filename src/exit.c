/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:06:36 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/03 16:19:43 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_all *all, int err)
{
	error_strings(err);
	free_on_exit(all, err);
	if (err > 11)
		mlx_destroy_window(all->img.mlx, all->img.mlx_win);
	exit(0);
	return (0);
}

void	free_on_exit(t_all *all, int err)
{
	if (err > 1)
		free(all->map.file);
	if (err > 1)
	{
		if (all->map.no)
			free(all->map.no);
		if (all->map.so)
			free(all->map.so);
		if (all->map.we)
			free(all->map.we);
		if (all->map.ea)
			free(all->map.ea);
	}
	if (err > 7)
		ft_freearr(all->map.map);
}

void	error_strings(int err)
{
	if (err == 0)
		printf(RED "Error\nFile doesn't have .cub extension\n" RESET);
	if (err == 1)
		printf(RED "Error\nFile doesn't exist\n" RESET);
	if (err == 2)
		printf(RED "Error\nTexture path not valid\n" RESET);
	if (err == 3)
		printf(RED "Error\nResolution line not valid\n" RESET);
	if (err == 4)
		printf(RED "Error\nColor line not valid\n" RESET);
	if (err == 5)
		printf(RED "Error\nRGB Value out of range\n" RESET);
	if (err == 6)
		printf(RED "Error\nFile not valid\n" RESET);
	if (err == 7)
		printf(RED "Error\nMemory fault\n" RESET);
	if (err == 8)
		printf(RED "Error\nMap not valid\n" RESET);
	if (err == 9)
		printf(RED "Error\nMore then one spawn position\n" RESET);
	error_strings_2(err);
}

void	error_strings_2(int err)
{
	if (err == 10)
		printf(RED "Error\nNo spawn position\n" RESET);
	if (err == 11)
		printf(RED "Error\nEpstein didn't kill himself\n" RESET);
	if (err == 12)
		printf(RED "Error\nXPM File doesn't exist\n" RESET);
	if (err > 50)
		printf(GREEN "Quit Cub3D succesfull\n" RESET);
}
