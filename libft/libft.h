/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:36:59 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/20 20:17:40 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
**	String
*/

int				ft_isalpha(int ch);
int				ft_isascii(int ch);
int				ft_isdigit(int ch);
int				ft_isalnum(int ch);
int				ft_isprint(int ch);
int				ft_isupcase(int ch);
int				ft_islowcase(int ch);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strdup(const char *str);
char			*ft_strrev(char const *str);
size_t			ft_strlen(const char *str);
char			*ft_strcat(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
void			ft_strclr(char *str);
char			*ft_strncat(char *dest, char *src, int nb);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_uppercase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
char			*ft_strcapitalize(char *str);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
**	Memory
*/

void			*ft_memccpy(void *dest, const void *src, int ch, size_t len);
void			*ft_memchr(const void *ptr, int ch, size_t len);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memset(void *buff, int ch, size_t len);

/*
**	Std
*/

int				ft_atoi(const char *str);
void			ft_bzero(void *buff, size_t len);
void			*ft_calloc(size_t num, size_t size);
char			*ft_itoa(int n);
int				ft_max_int(int a, int b);
int				ft_min_int(int a, int b);
void			ft_swap_int(int *a, int *b);

/*
**	List
*/

typedef	struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
int				ft_lstempty(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstat(t_list *lst, int index);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
void			ft_lstremove(t_list **lst, int index);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));


int				get_next_line(int fd, char **line);

#endif
