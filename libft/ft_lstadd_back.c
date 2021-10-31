/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 14:32:19 by nicky         #+#    #+#                 */
/*   Updated: 2021/06/16 19:59:51 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (!lst[0])
	{
		lst[0] = new;
		return ;
	}
	last = ft_lstlast(lst[0]);
	new->next = last->next;
	last->next = new;
}
