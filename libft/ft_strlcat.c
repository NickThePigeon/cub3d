/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 20:50:18 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:17:45 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			srclen;
	size_t			destlen;
	unsigned int	i;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (destlen < dstsize)
	{
		while (i < dstsize - destlen - 1 && src[i])
		{
			dst[destlen + i] = src[i];
			i++;
		}
		dst[destlen + i] = '\0';
		return (srclen + destlen);
	}
	return (srclen + dstsize);
}
