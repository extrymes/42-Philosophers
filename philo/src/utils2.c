/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:04:07 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 15:18:26 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_set_died(t_data *data)
{
	pthread_mutex_lock(&data->died_lock);
	data->is_died = 1;
	pthread_mutex_unlock(&data->died_lock);
}

int	ft_check_died(t_data *data)
{
	int	is_died;

	is_died = 0;
	pthread_mutex_lock(&data->died_lock);
	if (data->is_died)
		is_died = 1;
	pthread_mutex_unlock(&data->died_lock);
	return (is_died);
}

void	ft_increase_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_lock);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->eat_lock);
}

int	ft_get_eat(t_philo *philo)
{
	int	nb_eat;

	pthread_mutex_lock(&philo->eat_lock);
	nb_eat = philo->nb_eat;
	pthread_mutex_unlock(&philo->eat_lock);
	return (nb_eat);
}

int	ft_msleep(unsigned long ms, t_data *data)
{
	unsigned long	start;

	start = ft_current_time();
	while ((ft_current_time() - start) < ms)
	{
		if (ft_check_died(data))
			break ;
		usleep(500);
	}
	return (0);
}
