/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 23:55:16 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:06:56 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c))
			words += 1;
		i++;
	}
	if (s[i - 1] != c)
		words += 1;
	return (words);
}

static char	**ft_check_array(char **array, int f)
{
	f -= 1;
	while (f >= 0)
	{
		free(array[f]);
		f--;
	}
	free(array);
	return (NULL);
}

static char	**ft_fill_array(char **array, char *s, char c)
{
	int	i;
	int	f;
	int	len;

	i = 0;
	f = 0;
	while (s[i])
	{
		len = 0;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			array[f] = ft_substr((char *)s, i - len, len);
			if (!array[f])
				return (ft_check_array(array, f));
			f++;
		}
		else
			i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_calloc(ft_count_words((char *)s, c) + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = ft_fill_array(array, (char *)s, c);
	if (array == NULL)
		return (NULL);
	return (array);
}
