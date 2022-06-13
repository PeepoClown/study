/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:59 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/08 20:16:29 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int					ft_atoi(const char *str)
{
	int		result;
	int		sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str && *str >= 48 && *str <= 57)
		result = result * 10 + (*str++ - 48);
	return (result * sign);
}

int					ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned long long	get_time_in_ms(void)
{
	struct timeval		tv;
	unsigned long long	res;

	gettimeofday(&tv, NULL);
	res = (unsigned long long)tv.tv_sec * 1000 +
		(unsigned long long)tv.tv_usec / 1000;
	return (res);
}

void				ft_usleep(unsigned long long time)
{
	unsigned long long	start_time;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < time)
		usleep(200);
}

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
