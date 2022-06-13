/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:54:59 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/11 19:16:10 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	ptr_helper_print(char *str, t_params *params, bool is_flag_zero)
{
	int		accur;

	if (!is_flag_zero)
		params->count += ft_putnstr("0x", 2);
	if (params->point == true)
	{
		accur = params->accur;
		while (accur > (int)ft_strlen(str))
		{
			params->count += ft_putchar('0');
			accur--;
		}
	}
	params->count += ft_putnstr(str, ft_strlen(str));
}

static	void	ptr_helper(char *str, t_params *params)
{
	bool	is_flag_zero;

	is_flag_zero = false;
	if ((size_t)params->accur < ft_strlen(str))
		params->accur = ft_strlen(str);
	if (params->m_flag == true)
		ptr_helper_print(str, params, is_flag_zero);
	else
		is_flag_zero = (params->z_flag == true) ? true : false;
	if (is_flag_zero == true)
		params->count += ft_putnstr("0x", 2);
	while (params->width - 2 > params->accur)
	{
		params->count += ft_putchar(params->z_flag == true ? '0' : ' ');
		params->width--;
	}
	if (params->m_flag == false)
		ptr_helper_print(str, params, is_flag_zero);
}

void			display_ptr(t_params *params, va_list args)
{
	char				*ptr_str;
	unsigned long long	ptr;

	ptr = va_arg(args, unsigned long long);
	if (ptr == 0 && params->point == true && params->accur == 0)
	{
		if (params->m_flag == true)
			params->count += ft_putnstr("0x", 2);
		while (params->width-- > 2)
			params->count += ft_putchar(' ');
		if (params->m_flag == false)
			params->count += ft_putnstr("0x", 2);
		return ;
	}
	ptr_str = ft_hexlltoa(ptr);
	ptr_helper(ptr_str, params);
	free(ptr_str);
}
