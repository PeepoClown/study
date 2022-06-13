/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:04:29 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/11 17:31:37 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	set_specifier(t_params *params, va_list args)
{
	if (params->type == '%')
		display_percent(params);
	else if (params->type == 'c')
		display_char(params, args);
	else if (params->type == 's')
		display_str(params, args);
	else if (params->type == 'u')
		display_uint(params, args);
	else if (params->type == 'd' || params->type == 'i')
		display_int(params, args);
	else if (params->type == 'x' || params->type == 'X')
		display_hex(params, args);
	else if (params->type == 'p')
		display_ptr(params, args);
	else if (params->type != 0)
		display_other(params);
	else
		params->count = -1;
}
