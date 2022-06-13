/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:30:06 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/10 19:55:20 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	parse_flags(const char *format, t_params *params)
{
	while (format[params->pos] == '-' || format[params->pos] == '0')
	{
		if (format[params->pos] == '-')
			params->m_flag = true;
		if (format[params->pos] == '0')
			params->z_flag = true;
		params->pos++;
	}
}

void	parse_width(const char *format, t_params *params, va_list args)
{
	if (format[params->pos] == '*')
	{
		params->width = va_arg(args, int);
		if (params->width < 0)
		{
			params->width *= -1;
			params->m_flag = true;
		}
		params->pos++;
	}
	else
		while (ft_isdigit(format[params->pos]))
			params->width = params->width * 10 + (format[params->pos++] - 48);
}

void	parse_accur(const char *format, t_params *params, va_list args)
{
	bool minus;

	minus = false;
	if (format[params->pos] == '*')
	{
		params->accur = va_arg(args, int);
		minus = (params->accur < 0) ? true : false;
		params->pos++;
	}
	else
	{
		while (ft_isdigit(format[params->pos]) || format[params->pos] == '-')
		{
			if (format[params->pos] == '-')
				minus = true;
			else
				params->accur = params->accur * 10 + format[params->pos] - 48;
			params->pos++;
		}
	}
	if (minus == true)
	{
		params->accur = 0;
		params->point = false;
	}
}

void	parse_type(const char *format, t_params *params)
{
	while (format[params->pos] == '.')
		params->pos++;
	params->type = format[params->pos];
}

void	parse(const char *format, t_params *params, va_list args)
{
	parse_flags(format, params);
	parse_width(format, params, args);
	if (format[params->pos] == '.')
	{
		params->point = true;
		params->pos++;
		parse_accur(format, params, args);
	}
	parse_type(format, params);
	if (params->m_flag == true && params->z_flag == true)
		params->z_flag = false;
}
