/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:59:49 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/03 12:54:22 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list_gnl	*ft_lstnew_gnl(int fd)
{
	int		i;
	t_list_gnl	*elem;

	elem = (t_list_gnl*)malloc(sizeof(t_list_gnl));
	if (!elem)
		return (NULL);
	elem->fd = fd;
	elem->next = NULL;
	i = 0;
	elem->rem = (char*)malloc(BUFFER_SIZE);
	while (i < BUFFER_SIZE)
		elem->rem[i++] = '\0';
	return (elem);
}

void	ft_lstremove_gnl(t_list_gnl **lst, int fd)
{
	t_list_gnl *curr;
	t_list_gnl *prev;

	if (!lst)
		return ;
	curr = *lst;
	if (curr->next == NULL)
	{
		free(curr->rem);
		free(curr);
		*lst = NULL;
		return ;
	}
	prev = NULL;
	while (curr->fd != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!prev)
		*lst = curr->next;
	else
		prev->next = curr->next;
	free(curr->rem);
	free(curr);
}

char	*check_on_nl(char **nl_pos, char *rem)
{
	char *str;

	if ((*nl_pos = ft_strchr(rem, '\n')))
	{
		**nl_pos = '\0';
		str = ft_strdup(rem);
		ft_strcpy(rem, ++(*nl_pos));
	}
	else
	{
		str = ft_strdup(rem);
		while (*rem)
		{
			*rem = '\0';
			rem++;
		}
	}
	return (str);
}

int		get_line(int fd, char **line, char *rem)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_count;
	char	*nl_pos;
	char	*tmp;

	bytes_count = 1;
	*line = check_on_nl(&nl_pos, rem);
	while (!nl_pos && ((bytes_count = read(fd, buff, BUFFER_SIZE)) != 0))
	{
		buff[bytes_count] = '\0';
		if ((nl_pos = ft_strchr(buff, '\n')))
		{
			ft_strcpy(rem, ++nl_pos);
			nl_pos--;
			while (*nl_pos)
				*nl_pos++ = '\0';
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff)) || bytes_count < 0)
			return (-1);
		free(tmp);
	}
	if (ft_strlen(rem) || bytes_count)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list_gnl	*list;
	t_list_gnl			*curr;
	char				check;
	int					ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, &check, 0) < 0))
		return (-1);
	if (!list)
		list = ft_lstnew_gnl(fd);
	curr = list;
	while (curr->fd != fd)
	{
		if (!(curr->next))
			curr->next = ft_lstnew_gnl(fd);
		curr = curr->next;
	}
	if (!(ret = get_line(fd, line, curr->rem)))
		ft_lstremove_gnl(&list, fd);
	return (ret);
}
