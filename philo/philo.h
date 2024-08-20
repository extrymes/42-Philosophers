/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:43:51 by sabras            #+#    #+#             */
/*   Updated: 2024/08/20 11:34:34 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
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
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_each_philo_to_eat;
	int				must_eat;
	int				total_eat;
	unsigned long	time;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat;
	pthread_t		thread;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	fork_m;
	unsigned long	last_meal;
	t_data			*data;
}	t_philo;

// Routine
void			*routine(void	*ph);

// Utils
int				ft_atoi(char *s);
void			ft_dest_mutex(int nb_philos, t_philo *philos);
unsigned long	ft_current_time(void);
unsigned long	ft_elapsed_time(unsigned long time);
void			ft_print_error(char *s);

#endif
