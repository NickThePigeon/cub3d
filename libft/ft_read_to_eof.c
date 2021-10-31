/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_to_eof.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 15:03:19 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/12 16:25:42 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join_free_s1(char *s1, char *s2)
{
	int		len;
	char	*ret_join;

	if (!s2)
		return (s1);
	len = ft_strlen(s1);
	ret_join = (char *)malloc((ft_strlen(s2) + len + 1) * sizeof(char));
	if (!ret_join)
		return (NULL);
	if (s1)
	{
		ft_strcpy(ret_join, s1);
		free(s1);
	}
	ft_strcpy(ret_join + len, s2);
	return (ret_join);
}

int	read_to_eof(char *filename, char **file)
{
	int			fd;
	int			ret;
	static char	buf[124];

	fd = open(filename, O_RDONLY);
	if (fd < 0 || fd > 1024 || !file)
		return (0);
	ret = 1;
	*file = 0;
	while (ret > 0)
	{
		ret = read(fd, buf, 124);
		buf[ret] = '\0';
		*file = ft_join_free_s1(*file, buf);
		if (ret == -1)
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}
