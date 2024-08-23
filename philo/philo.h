/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:43:51 by sabras            #+#    #+#             */
/*   Updated: 2024/08/23 17:14:13 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# define GRAY "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

typedef struct s_data
{
	int				nb_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_to_think;
	int				must_eat;
	int				is_died;
	unsigned long	time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	died_lock;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals;
	unsigned long	last_meal;
	pthread_t		thread;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	fork_m;
	pthread_mutex_t	eat_lock;
	t_data			*data;
}	t_philo;

// Routine
void			*routine(void	*ph);
void			*checker(void *ph);

// States
void			ft_set_died(t_data *data);
int				ft_check_died(t_data *data);
void			ft_eat_meal(t_philo *philo);
int				ft_get_meals(t_philo *philo);
unsigned long	ft_get_last_meal(t_philo *philo);

// Time
unsigned long	ft_curr_time(void);
unsigned long	ft_elap_time(unsigned long time);
int				ft_msleep(unsigned long ms, t_data *data);

// Utils
int				ft_atoi(char *s);
void			ft_take_forks(t_philo *philo);
void			ft_dest_mutexes(t_data *data, t_philo *philos, int nb_philos);
void			ft_print(t_philo *philo, char *is_doing);
void			ft_error(char *s);

#endif
