/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <wupdegra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:29:37 by wupdegra          #+#    #+#             */
/*   Updated: 2020/12/11 16:39:28 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

extern bool			g_dead;

typedef struct		s_philo
{
	int					index;
	sem_t				*forks;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_times;
	int					curr_meals;
	unsigned long long	start_time;
	unsigned long long	last_meal_time;
	sem_t				*output_sem;
	sem_t				*status_sem;
}					t_philo;

typedef struct		s_params
{
	int					philo_count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_times;
	pthread_t			*threads;
	sem_t				*forks;
	t_philo				*philos;
	unsigned long long	start_time;
	sem_t				*output_sem;
	sem_t				*status_sem;
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
