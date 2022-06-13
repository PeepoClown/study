/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:22:29 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/07 16:01:41 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		ft_get_hex_size(unsigned int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char			*ft_hextoa(unsigned int num, int letter)
{
	char	*str;
	int		length;

	if (num == 0)
		return (ft_strdup("0"));
	length = ft_get_hex_size(num);
	if (!(str = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	while (num > 0)
	{
		if (num % 16 < 10)
			str[length - 1] = num % 16 + 48;
		else if (letter == 'X')
			str[length - 1] = num % 16 + 55;
		else
			str[length - 1] = num % 16 + 87;
		num /= 16;
		length--;
	}
	return (str);
}
