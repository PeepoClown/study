/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:28:11 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/11 16:41:09 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

bool		g_dead;

static bool	init_params_helper(t_params *params)
{
	int		i;

	i = 0;
	while (i < params->philo_count)
	{
		params->philos[i].index = i + 1;
		params->philos[i].forks = params->forks;
		params->philos[i].time_to_die = params->time_to_die;
		params->philos[i].time_to_eat = params->time_to_eat;
		params->philos[i].time_to_sleep = params->time_to_sleep;
		params->philos[i].meal_times = params->meal_times;
		params->philos[i].curr_meals = 0;
		params->philos[i].start_time = params->start_time;
		params->philos[i].last_meal_time = get_time_in_ms();
		params->philos[i].output_sem = params->output_sem;
		params->philos[i].status_sem = params->status_sem;
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
	sem_unlink("/forks");
	if ((params->forks = sem_open("/forks", O_CREAT, 0644,
		params->philo_count)) == SEM_FAILED)
		return (ft_error("Can't create semaphore"));
	if (!(params->philos = (t_philo*)malloc(sizeof(t_philo)
		* params->philo_count)))
		return (ft_error("Can't allocate memory"));
	params->start_time = get_time_in_ms();
	sem_unlink("/output");
	if ((params->output_sem = sem_open("/output", O_CREAT, 0644,
		1)) == SEM_FAILED)
		return (ft_error("Can't create semaphore"));
	sem_unlink("/status");
	if ((params->status_sem = sem_open("/status", O_CREAT, 0644,
		1)) == SEM_FAILED)
		return (ft_error("Can't create semaphore"));
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
	if (params->threads)
		free(params->threads);
	if (params->forks)
		sem_close(params->forks);
	sem_close(params->output_sem);
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
