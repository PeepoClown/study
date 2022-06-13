/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:59:43 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/03 12:21:51 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

# define BUFFER_SIZE 32

/*
** List
*/

typedef struct	s_list_gnl
{
	int					fd;
	char				*rem;
	struct s_list_gnl	*next;
}				t_list_gnl;

t_list_gnl		*ft_lstnew_gnl(int fd);
void			ft_lstremove_gnl(t_list_gnl **lst, int fd);

/*
** Gnl
*/

int				get_next_line(int fd, char **line);

#endif
