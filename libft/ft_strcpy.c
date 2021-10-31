/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 15:31:21 by nduijf        #+#    #+#                 */
/*   Updated: 2021/10/12 16:26:36 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
