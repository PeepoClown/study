/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:48 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 16:31:41 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int size_to_find;

	size_to_find = ft_strlen(to_find);
	if (size_to_find == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j == size_to_find - 1)
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
