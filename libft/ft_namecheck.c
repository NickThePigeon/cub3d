/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_namecheck.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:14:45 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:16:21 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_namecheck(char *str, char *name)
{
	int	i;

	i = 0;
	while (str[i] == name[i])
	{
		if (str[i + 1] == '\0' && name[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
