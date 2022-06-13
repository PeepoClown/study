/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:39:36 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/09 17:57:36 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstat(t_list *lst, int index)
{
	if (!lst || index >= ft_lstsize(lst))
		return (NULL);
	while (index--)
		lst = lst->next;
	return (lst);
}
