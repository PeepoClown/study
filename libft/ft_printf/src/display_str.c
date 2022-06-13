/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:57:55 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/08 15:49:03 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	display_str(t_params *params, va_list args)
{
	char	*str;
	int		symbols;

	str = va_arg(args, char*);
	if (!str)
		str = "(null)";
	if (params->point == true)
		symbols = (params->accur < (int)ft_strlen(str)) ? (size_t)params->accur
			: ft_strlen(str);
	else
		symbols = ft_strlen(str);
	if (params->m_flag == true)
		params->count += ft_putnstr(str, symbols);
	while (params->width > symbols)
	{
		params->count += ft_putchar(params->z_flag == true ? '0' : ' ');
		params->width--;
	}
	if (params->m_flag == false)
		params->count += ft_putnstr(str, symbols);
}
