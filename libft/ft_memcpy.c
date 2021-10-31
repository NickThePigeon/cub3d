/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:57:27 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/17 12:10:27 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*copy_source;
	char			*copy_dest;
	unsigned int	i;

	if (!dest && !src)
		return (0);
	copy_dest = (char *)dest;
	copy_source = (char *)src;
	i = 0;
	while (i < n)
	{
		copy_dest[i] = copy_source[i];
		i++;
	}
	return (copy_dest);
}
