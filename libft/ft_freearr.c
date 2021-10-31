/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freearr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:27:24 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:00:52 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_freearr(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (1);
	}
	else
		return (-1);
}
