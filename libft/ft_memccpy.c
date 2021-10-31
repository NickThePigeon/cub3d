/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:00:44 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/17 11:46:35 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*copy_source;
	char			*copy_dest;
	unsigned int	i;

	copy_dest = (char *)dest;
	copy_source = (char *)src;
	i = 0;
	while (i < n)
	{
		copy_dest[i] = copy_source[i];
		if (copy_source[i] == (char)c)
			return (&copy_dest[i + 1]);
		i++;
	}
	return (0);
}
