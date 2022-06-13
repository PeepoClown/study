/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:19:29 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 16:46:41 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		check_for_beg(char *str, int i)
{
	if (str[i - 1] == ' ' || str[i - 1] == '-')
		return (1);
	if (str[i - 1] == '+' || str[i] == str[0])
		return (1);
	return (0);
}

char			*ft_strcapitalize(char *str)
{
	int i;
	int word_index;

	i = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		if (word_index)
			if (ft_isupcase(str[i]))
				str[i] += 32;
		if (!word_index)
			if (ft_islowcase(str[i]) || ft_isupcase(str[i]))
			{
				word_index = 1;
				if (ft_islowcase(str[i]))
					if (check_for_beg(str, i))
						str[i] -= 32;
			}
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			word_index = 0;
		i++;
	}
	return (str);
}
