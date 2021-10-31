/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:53:01 by nduijf        #+#    #+#                 */
/*   Updated: 2021/06/16 20:02:58 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*newstr1;
	unsigned char	*newstr2;

	newstr1 = (unsigned char *)str1;
	newstr2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (newstr1[i] != newstr2[i])
			return (newstr1[i] - newstr2[i]);
		i++;
	}
	return (0);
}
