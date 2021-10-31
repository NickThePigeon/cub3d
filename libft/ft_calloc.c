/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 14:46:10 by nduijf        #+#    #+#                 */
/*   Updated: 2021/06/16 20:17:52 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	ptr = malloc(nitems * size);
	if (ptr)
		ft_bzero(ptr, nitems * size);
	return (ptr);
}
