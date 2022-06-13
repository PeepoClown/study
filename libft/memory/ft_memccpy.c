/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:10:43 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 15:55:57 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dest, const void *src, int ch, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (len--)
	{
		*d = *s;
		d++;
		s++;
		if (*(d - 1) == (unsigned char)ch)
			return (d);
	}
	return (NULL);
}
