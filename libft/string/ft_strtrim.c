/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:00:47 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 15:57:45 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	size_t		ft_is_trim(char ch, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (ch == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

static	size_t		ft_get_end_pos(char const *s, char const *set)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i && ft_is_trim(*(s + i), set))
		i--;
	return (i + 1);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (ft_is_trim(*(s1 + start), set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_get_end_pos(s1, set);
	str = (char*)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + start, end - start);
	str[end - start] = '\0';
	return (str);
}
