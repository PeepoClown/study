/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:14:43 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/06 15:57:10 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		ft_is_word_break(char c, char ch)
{
	if (c == ch || c == '\0')
		return (1);
	return (0);
}

static	size_t	ft_count_words(char const *str, char ch)
{
	int		i;
	size_t	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_is_word_break(str[i + 1], ch) &&
			!ft_is_word_break(str[i], ch))
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_insert_word(char const *str, char ch)
{
	size_t	i;
	size_t	size;
	char	*word;

	size = 0;
	while (str[size] && str[size] != ch)
		size++;
	word = (char*)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count_words;
	char	**words;

	count_words = ft_count_words(s, c);
	if (!s || !(words = (char**)malloc(sizeof(char*) *
			(count_words + 1))))
		return (NULL);
	i = 0;
	while (i < count_words)
	{
		while (*s == c)
			s++;
		if (!(words[i] = ft_insert_word(s, c)))
		{
			while (i > 0)
				free(words[i--]);
			free(words);
			return (NULL);
		}
		s += ft_strlen(words[i]);
		i++;
	}
	words[i] = NULL;
	return (words);
}
