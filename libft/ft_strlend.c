/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlend.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:27:43 by nduijf        #+#    #+#                 */
/*   Updated: 2021/11/03 16:22:58 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlend(const char *str, char c)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0' && str[n] != c)
		n++;
	return (n);
}
