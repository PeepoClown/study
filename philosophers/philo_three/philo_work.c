/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:51:29 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/06 18:28:37 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*philo_check(void *data)
{
	t_philo	*philo;

	philo = (t_philo*)data;
	while (!g_dead && (philo->curr_meals != philo->meal_times))
	{
		usleep(200);
		sem_wait(philo->status_sem);
		if (g_dead)
			exit(1);
		if (!g_dead && get_time_in_ms() - philo->last_meal_time >
			(unsigned long long)philo->time_to_die)
		{
			g_dead = true;
			print_state(philo, "died");
			exit(1);
		}
		sem_post(philo->status_sem);
	}
	return (NULL);
}

static void	philo_eat(t_philo *philo)
{
	sem_wait(philo->forks);
	if (g_dead)
	{
		sem_post(philo->forks);
		exit(1);
	}
	print_state(philo, "has taken a fork");
	sem_wait(philo->forks);
	if (g_dead)
	{
		sem_post(philo->forks);
		sem_post(philo->forks);
		exit(1);
	}
	print_state(philo, "has taken a fork");
	philo->last_meal_time = get_time_in_ms();
	print_state(philo, "is eating");
	philo->curr_meals++;
	ft_usleep(philo->time_to_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (g_dead)
		exit(1);
}

void		philo_work(void *data)
{
	t_philo		*philo;
	pthread_t	checker;

	philo = (t_philo*)data;
	if (pthread_create(&checker, NULL, philo_check, data))
	{
		ft_error("Can't create thread");
		return ;
	}
	if (philo->index % 2 == 0)
		ft_usleep(50);
	philo->last_meal_time = get_time_in_ms();
	while (philo->curr_meals != philo->meal_times)
	{
		print_state(philo, "is thinking");
		philo_eat(philo);
		print_state(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep);
	}
	exit(0);
}
