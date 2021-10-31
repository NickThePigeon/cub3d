/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 22:38:09 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/24 11:47:19 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	int				i;
	unsigned int	lenght;

	if (!s)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	lenght = len + start;
	if (start <= ft_strlen(s))
	{
		while (start < lenght)
		{
			newstr[i] = s[start];
			i++;
			start++;
		}
	}
	newstr[i] = '\0';
	return (newstr);
}
