/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:58:01 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/08 19:40:53 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

bool		g_dead;

static bool	init_params_helper(t_params *params)
{
	int		i;

	i = 0;
	while (i < params->philo_count)
		if (pthread_mutex_init(&params->forks[i++], NULL))
			return (ft_error("Can't initialize mutex"));
	i = 0;
	while (i < params->philo_count)
	{
		params->philos[i].index = i + 1;
		params->philos[i].left_fork = (i != 0) ? &params->forks[i - 1]
			: &params->forks[params->philo_count - 1];
		params->philos[i].right_fork = &params->forks[i];
		params->philos[i].time_to_die = params->time_to_die;
		params->philos[i].time_to_eat = params->time_to_eat;
		params->philos[i].time_to_sleep = params->time_to_sleep;
		params->philos[i].meal_times = params->meal_times;
		params->philos[i].curr_meals = 0;
		params->philos[i].start_time = params->start_time;
		params->philos[i].last_meal_time = get_time_in_ms();
		params->philos[i].output_mutex = &params->output_mutex;
		params->philos[i].status_mutex = &params->status_mutex;
		i++;
	}
	return (true);
}

static bool	init_params(t_params *params, char **args, int args_count)
{
	params->philo_count = ft_atoi(args[0]);
	params->time_to_die = ft_atoi(args[1]);
	params->time_to_eat = ft_atoi(args[2]);
	params->time_to_sleep = ft_atoi(args[3]);
	params->meal_times = (args_count > 4) ? ft_atoi(args[4]) : -1;
	if (!(params->threads = (pthread_t*)malloc(sizeof(pthread_t)
		* params->philo_count)))
		return (ft_error("Can't allocate memory"));
	if (!(params->forks = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
		* params->philo_count)))
		return (ft_error("Can't allocate memory"));
	if (!(params->philos = (t_philo*)malloc(sizeof(t_philo)
		* params->philo_count)))
		return (ft_error("Can't allocate memory"));
	params->start_time = get_time_in_ms();
	if (pthread_mutex_init(&params->output_mutex, NULL))
		return (ft_error("Can't initialize mutex"));
	if (pthread_mutex_init(&params->status_mutex, NULL))
		return (ft_error("Can't initialize mutex"));
	return (init_params_helper(params));
}

static bool	create_threads(t_params *params)
{
	int		i;

	i = 0;
	while (i < params->philo_count)
	{
		if (pthread_create(&params->threads[i], NULL, philo_work,
			(void*)&params->philos[i]))
			return (ft_error("Can't create thread"));
		i++;
	}
	i = 0;
	while (i < params->philo_count)
	{
		if (pthread_join(params->threads[i], NULL))
			return (ft_error("Can't join with main thread"));
		i++;
	}
	return (true);
}

static void	destroy_params(t_params *params)
{
	int		i;

	if (params->threads)
		free(params->threads);
	i = 0;
	if (params->forks)
	{
		while (i < params->philo_count)
			pthread_mutex_destroy(&params->forks[i++]);
		free(params->forks);
	}
	pthread_mutex_destroy(&params->output_mutex);
	pthread_mutex_destroy(&params->status_mutex);
	if (params->philos)
		free(params->philos);
}

int			main(int argc, char **argv)
{
	t_params	params;

	g_dead = false;
	if (!validate_arguments(argv + 1, argc - 1))
		return (1);
	if (!init_params(&params, argv + 1, argc - 1))
		return (1);
	if (!create_threads(&params))
		return (1);
	destroy_params(&params);
	return (0);
}
