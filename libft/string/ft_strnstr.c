/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:23:56 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 15:57:41 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	i = 0;
	while (i < ft_strlen(s1) && i < len)
	{
		j = 0;
		while (j < ft_strlen(s2) && (i + j) < len)
		{
			if (s1[i + j] != s2[j])
				break ;
			j++;
		}
		if (j == ft_strlen(s2))
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
