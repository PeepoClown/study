/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:49 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/08 20:18:06 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	*philo_check(void *data)
{
	t_philo	*philo;

	philo = (t_philo*)data;
	while (!g_dead && (philo->curr_meals != philo->meal_times))
	{
		usleep(200);
		pthread_mutex_lock(philo->status_mutex);
		if (g_dead)
			return (NULL);
		if (!g_dead && get_time_in_ms() - philo->last_meal_time >
			(unsigned long long)philo->time_to_die)
		{
			g_dead = true;
			print_state(philo, "died");
			return (NULL);
		}
		pthread_mutex_unlock(philo->status_mutex);
	}
	return (NULL);
}

static int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (g_dead)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (g_dead)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_state(philo, "has taken a fork");
	philo->last_meal_time = get_time_in_ms();
	print_state(philo, "is eating");
	philo->curr_meals++;
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (g_dead)
		return (0);
	return (1);
}

void		*philo_work(void *data)
{
	t_philo		*philo;
	pthread_t	checker;

	philo = (t_philo*)data;
	if (pthread_create(&checker, NULL, philo_check, data))
		return ((void*)ft_error("Can't create thread"));
	if (philo->index % 2 == 0)
		ft_usleep(50);
	philo->last_meal_time = get_time_in_ms();
	while (!g_dead && (philo->curr_meals != philo->meal_times))
	{
		print_state(philo, "is thinking");
		if (!philo_eat(philo))
			return (NULL);
		print_state(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep);
	}
	return (NULL);
}
