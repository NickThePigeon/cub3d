/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:24:30 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 20:20:09 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int argument)
{
	if (argument >= 65 && argument <= 90)
	{
		argument += 32;
		return (argument);
	}
	else
	{
		return (argument);
	}
}
