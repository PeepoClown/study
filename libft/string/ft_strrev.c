/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:53:11 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 16:59:56 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrev(char const *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = (int)ft_strlen(str) - 1;
	result = (char*)malloc(sizeof(char) * (j + 1));
	while (i < j)
	{
		result[i] = str[j];
		result[j] = str[i];
		i++;
		j--;
	}
	result[ft_strlen(str)] = '\0';
	return (result);
}
