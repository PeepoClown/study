/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:28:45 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 15:55:59 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *ptr, int ch, size_t len)
{
	unsigned char	*p;

	p = (unsigned char*)ptr;
	while (len--)
	{
		if (*p == (unsigned char)ch)
			return (p);
		p++;
	}
	return (NULL);
}
