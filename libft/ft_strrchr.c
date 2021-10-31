/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 09:37:49 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:14:41 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	lenght;

	lenght = ft_strlen(str);
	while (lenght >= 0)
	{
		if (str[lenght] == c)
			return ((char *)&str[lenght]);
		lenght--;
	}
	return (0);
}
