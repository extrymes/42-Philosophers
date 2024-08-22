/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:30:43 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 22:30:02 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void	*ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (1)
	{
		ft_take_forks(philo);
		ft_eat_meal(philo);
		ft_msleep(philo->data->time_to_eat, philo->data);
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_unlock(philo->fork_l);
		ft_print(philo, "is sleeping 💤");
		ft_msleep(philo->data->time_to_sleep, philo->data);
		ft_print(philo, "is thinking 💭");
		ft_msleep(philo->data->time_to_think, philo->data);
		if (ft_check_died(philo->data))
			break ;
	}
	return (NULL);
}

void	*checker(void *ph)
{
	t_philo	*philos;
	t_data	*data;
	int		count;
	int		i;

	philos = (t_philo *)ph;
	data = philos[0].data;
	i = 0;
	while (1)
	{
		if (ft_curr_time() - ft_get_last_meal(&philos[i]) >= data->time_to_die)
			return (ft_print(&philos[i], "died 💀"), ft_set_died(data), NULL);
		if (i == 0)
			count = 0;
		if (ft_get_meals(&philos[i]) >= data->must_eat)
			count++;
		if (count == data->nb_philos && data->must_eat != -1)
			return (ft_set_died(data), NULL);
		i = (i + 1) % data->nb_philos;
	}
	return (NULL);
}
