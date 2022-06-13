/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:33:44 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/12 19:31:41 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	int_helper_print(char *str, int num, t_params *params)
{
	int		accur;

	if (num < 0 && params->point == true)
		params->count += ft_putchar('-');
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

static	void	int_helper(char *str, int num, t_params *params)
{
	if (params->m_flag == true)
		int_helper_print(str, num, params);
	if ((size_t)params->accur < ft_strlen(str))
		params->accur = ft_strlen(str);
	while (params->width > params->accur)
	{
		params->count += ft_putchar((params->z_flag == true &&
										params->point == false) ? '0' : ' ');
		params->width--;
	}
	if (params->m_flag == false)
		int_helper_print(str, num, params);
}

static	bool	print_min_int(int num, t_params *params)
{
	if (num != INT_MIN)
		return (false);
	if (!params->m_flag && !params->z_flag && !params->point)
	{
		while (params->width-- > 11)
			params->count += ft_putchar(' ');
		params->count += ft_putnstr("-2147483648", 12);
		return (true);
	}
	if (params->m_flag == true && params->accur == 0)
	{
		params->count += ft_putnstr("-2147483648", 12);
		while (params->width-- > 11)
			params->count += ft_putchar(' ');
		return (true);
	}
	if (params->point == true || params->z_flag == true)
	{
		if (params->z_flag == true && params->point == false)
			params->count += ft_putchar('-');
		params->width--;
	}
	int_helper("2147483648", -2147483648, params);
	return (true);
}

void			display_int(t_params *params, va_list args)
{
	char	*num_str;
	int		num;
	int		old_num;

	num = va_arg(args, int);
	old_num = num;
	if (!num && params->point == true && !params->accur)
	{
		while (params->width--)
			params->count += ft_putchar(' ');
		return ;
	}
	if (print_min_int(num, params) == true)
		return ;
	if (num < 0 && (params->point == true || params->z_flag == true))
	{
		if (params->z_flag == true && params->point == false)
			params->count += ft_putchar('-');
		num *= -1;
		params->width--;
	}
	num_str = ft_itoa(num);
	int_helper(num_str, old_num, params);
	free(num_str);
}
