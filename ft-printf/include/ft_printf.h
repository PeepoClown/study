/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:59:57 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/12 18:12:12 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

int				ft_printf(const char *format, ...);

/*
**	Params struct
*/

typedef	struct	s_params
{
	size_t	pos;
	ssize_t	count;
	bool	m_flag;
	bool	z_flag;
	int		width;
	bool	point;
	int		accur;
	char	type;
}				t_params;

/*
**	Utils functions
*/

void			parse(const char *format, t_params *params, va_list args);
void			parse_flags(const char *format, t_params *params);
void			parse_width(const char *format, t_params *params, va_list args);
void			parse_accur(const char *format, t_params *params, va_list args);
void			parse_type(const char *format, t_params *params);
void			set_specifier(t_params *params, va_list args);
void			display_percent(t_params *params);
void			display_char(t_params *params, va_list args);
void			display_str(t_params *params, va_list args);
void			display_uint(t_params *params, va_list args);
void			display_int(t_params *params, va_list args);
void			display_hex(t_params *params, va_list args);
void			display_ptr(t_params *params, va_list args);
void			display_other(t_params *params);

/*
**	LibC functions
*/

int				ft_putchar(char c);
int				ft_isdigit(char c);
size_t			ft_strlen(const char *str);
int				ft_putnstr(char *str, int n);
char			*ft_strdup(const char *str);
char			*ft_itoa(int num);
char			*ft_uitoa(unsigned int num);
char			*ft_hextoa(unsigned int num, int letter);
char			*ft_hexlltoa(unsigned long long num);

#endif
