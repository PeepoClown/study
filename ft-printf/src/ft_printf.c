/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:03:41 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/05 14:43:37 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	first_init(t_params *params)
{
	params->pos = 0;
	params->count = 0;
}

static	void	reset_params(t_params *params)
{
	params->m_flag = false;
	params->z_flag = false;
	params->width = 0;
	params->point = false;
	params->accur = 0;
	params->type = '\0';
}

static	void	parse_format(const char *format, t_params *params, va_list args)
{
	while (format[params->pos] != '\0')
	{
		if (format[params->pos] == '%')
		{
			params->pos++;
			if (format[params->pos] == '\0')
			{
				params->count = -1;
				return ;
			}
			reset_params(params);
			parse(format, params, args);
			set_specifier(params, args);
			if (params->count == -1)
				return ;
		}
		else
			params->count += ft_putchar(format[params->pos]);
		params->pos++;
	}
}

int				ft_printf(const char *format, ...)
{
	ssize_t		total;
	va_list		args;
	t_params	*params;

	if (!format || !(params = (t_params*)malloc(sizeof(t_params))))
		return (-1);
	first_init(params);
	va_start(args, format);
	parse_format(format, params, args);
	va_end(args);
	total = params->count;
	free(params);
	return (total);
}
