/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 09:51:06 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 19:59:26 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len)
	{
		while ((haystack[i] == needle[k]) && (i < len))
		{
			if (needle[k + 1] == '\0')
			{
				return ((char *)&haystack[i - k]);
			}
			i++;
			k++;
		}
		i++;
		i = i - k;
		k = 0;
	}
	return (0);
}
