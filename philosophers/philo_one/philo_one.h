/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:29:37 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/08 17:47:18 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

extern bool			g_dead;

typedef struct		s_philo
{
	int					index;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_times;
	int					curr_meals;
	unsigned long long	start_time;
	unsigned long long	last_meal_time;
	pthread_mutex_t		*output_mutex;
	pthread_mutex_t		*status_mutex;
}					t_philo;

typedef struct		s_params
{
	int					philo_count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_times;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	unsigned long long	start_time;
	pthread_mutex_t		output_mutex;
	pthread_mutex_t		status_mutex;
}					t_params;

void				*philo_work(void *data);
bool				validate_arguments(char **args, int args_count);
bool				ft_error(const char *error_msg);
void				print_state(t_philo *philo, const char *msg);
int					ft_atoi(const char *str);
int					ft_strlen(const char *str);
unsigned long long	get_time_in_ms(void);
void				ft_usleep(unsigned long long time);
char				*ft_strcpy(char *dest, char *src);

#endif
