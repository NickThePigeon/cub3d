/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 13:37:24 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:16:56 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_str(char str, char *set)
{
	int	index;
	int	len;

	len = ft_strlen(set);
	index = 0;
	while (index < len)
	{
		if (set[index] == str)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		start;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(set));
	while (ft_check_str(s1[i], (char *)set))
	{
		i++;
	}
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > start && ft_check_str(s1[i], (char *)set))
	{
		i--;
	}
	newstr = ft_substr(s1, start, i - start + 1);
	return (newstr);
}
