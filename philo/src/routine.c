/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:30:43 by sabras            #+#    #+#             */
/*   Updated: 2024/08/20 11:09:21 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *philo, char *is_doing);

void	*routine(void	*ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->id % 2 == 0)
		usleep(1000);
	philo->last_meal = ft_current_time();
	while (1)
	{
		pthread_mutex_lock(philo->fork_r);
		ft_print(philo, "has taken a fork 🍴");
		pthread_mutex_lock(philo->fork_l);
		ft_print(philo, "has taken a fork 🍴");
		philo->eat++;
		if (philo->eat == philo->data->must_eat)
			philo->data->total_eat++;
		philo->last_meal = ft_current_time();
		ft_print(philo, "is eating 🍝");
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_unlock(philo->fork_l);
		ft_print(philo, "is sleeping 💤");
		usleep(philo->data->time_to_sleep * 1000);
		ft_print(philo, "is thinking 💭");
	}
	return (NULL);
}

void	ft_print(t_philo *philo, char *is_doing)
{
	printf("%lums\t%d %s\n", ft_elapsed_time(philo->data->time),
		philo->id + 1, is_doing);
}
