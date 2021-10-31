/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_free_s1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 16:12:29 by nduijf        #+#    #+#                 */
/*   Updated: 2021/10/12 16:26:22 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_s1(char *s1, char *s2, int lens2)
{
	int		i[2];
	char	*newstr;

	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) * sizeof(char)) + 1);
	if (!newstr)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	if (s1)
	{
		while (s1[i[0]])
		{
			newstr[i[0]] = s1[i[0]];
			i[0]++;
		}
	}
	while (i[1] < lens2)
	{
		newstr[i[0]] = s2[i[1]];
		i[0]++;
		i[1]++;
	}
	newstr[i[0]] = '\0';
	return (newstr);
}
