/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:25:53 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/08 15:47:50 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	display_char(t_params *params, va_list args)
{
	unsigned char	symbol;

	symbol = (unsigned char)va_arg(args, int);
	if (params->m_flag == true)
		params->count += ft_putchar(symbol);
	while (params->width > 1)
	{
		params->count += ft_putchar(params->z_flag == true ? '0' : ' ');
		params->width--;
	}
	if (params->m_flag == false)
		params->count += ft_putchar(symbol);
}
