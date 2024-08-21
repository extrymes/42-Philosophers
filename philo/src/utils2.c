/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:04:07 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 22:30:02 by sabras           ###   ########.fr       */
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

void	ft_eat_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_lock);
	ft_print(philo, "is eating 🍝");
	philo->meals++;
	philo->last_meal = ft_curr_time();
	pthread_mutex_unlock(&philo->eat_lock);
}

int	ft_get_meals(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->eat_lock);
	meals = philo->meals;
	pthread_mutex_unlock(&philo->eat_lock);
	return (meals);
}

unsigned long	ft_get_last_meal(t_philo *philo)
{
	unsigned long	last_meal;

	pthread_mutex_lock(&philo->eat_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->eat_lock);
	return (last_meal);
}
