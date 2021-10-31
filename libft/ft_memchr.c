/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:29:55 by nduijf        #+#    #+#                 */
/*   Updated: 2021/01/28 17:26:03 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	const char		*newstr;

	newstr = str;
	i = 0;
	while (i < n)
	{
		if (newstr[i] == c)
			return ((unsigned char *)&newstr[i]);
		i++;
	}
	return (0);
}
