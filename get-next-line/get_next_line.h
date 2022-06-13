/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 20:06:04 by wupdegra          #+#    #+#             */
/*   Updated: 2020/05/21 12:22:28 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Utils
*/

int				ft_strlen(const char *str);
char			*ft_strchr(const char *str, int ch);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);

/*
** List
*/

typedef struct	s_list
{
	int				fd;
	char			*rem;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(int fd);
void			ft_lstclr(t_list **list);

/*
** Gnl
*/

int				get_next_line(int fd, char **line);

#endif
