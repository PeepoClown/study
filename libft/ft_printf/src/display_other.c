/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:50:04 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/08 15:51:00 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	display_other(t_params *params)
{
	if (params->m_flag == true)
		params->count += ft_putchar(params->type);
	while (params->width > 1)
	{
		params->count += ft_putchar(params->z_flag == true ? '0' : ' ');
		params->width--;
	}
	if (params->m_flag == false)
		params->count += ft_putchar(params->type);
}
