/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:16:24 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 15:56:14 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = (unsigned char*)malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero((unsigned char*)ptr, num * size);
	return (ptr);
}
