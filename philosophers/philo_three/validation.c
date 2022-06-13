/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:50:51 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/05 16:50:53 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static bool	validate_number(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '+')
		i++;
	if (i == ft_strlen(str))
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	if (i != ft_strlen(str))
		return (false);
	return (true);
}

bool		validate_arguments(char **args, int args_count)
{
	const char	*errors[5] = {
		"Error : Invalid count of philos", "Error : Invalid time to die",
		"Error : Invalid time to eat", "Error : Invalid time to sleep",
		"Error : Invalid eat times count"
	};
	int			i;

	if (args_count < 4 || args_count > 5)
		return (ft_error("Ivalid count of params"));
	i = 0;
	while (i < args_count)
	{
		if (!validate_number(args[i]))
			return (ft_error(errors[i]));
		i++;
	}
	if (ft_atoi(args[0]) < 2)
		return (ft_error("Invalid count of philos"));
	return (true);
}
