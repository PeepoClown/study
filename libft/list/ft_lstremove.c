/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:45:59 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/09 17:55:51 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstremove(t_list **lst, int index)
{
	t_list	*list;
	t_list	*elem;

	if (index >= ft_lstsize(*lst) || !lst || !(*lst))
		return ;
	if (index == 0)
	{
		list = ft_lstat(*lst, 1);
		free(*lst);
		*lst = list;
		return ;
	}
	list = ft_lstat(*lst, index - 1);
	elem = ft_lstat(*lst, index);
	list->next = ft_lstat(*lst, index + 1);
	free(elem);
}
