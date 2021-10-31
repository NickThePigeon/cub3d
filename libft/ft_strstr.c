/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/23 11:36:16 by nduijf        #+#    #+#                 */
/*   Updated: 2021/06/16 19:58:47 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i] == needle[k])
		{
			if (needle[k + 1] == '\0')
			{
				return (&haystack[i - k]);
			}
			i++;
			k++;
		}
		if (haystack[i] == '\0')
			return (0);
		i++;
		i = i - k;
		k = 0;
	}
	return (0);
}
