/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 19:32:28 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:19:44 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_int_lenght(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_get_int_lenght(n);
	i = 0;
	nb = (char *)ft_calloc(len + 1, sizeof(char));
	if (!nb)
		return (0);
	if (n < 0)
	{
		nb[i] = '-';
		n = n * -1;
		i++;
	}
	while (i < len)
	{
		nb[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (nb);
}
