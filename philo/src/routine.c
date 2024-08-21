/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:30:43 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 15:21:00 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *philo, char *is_doing);

void	*routine(void	*ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->id % 2 == 0)
		ft_msleep(1, philo->data);
	while (1)
	{
		pthread_mutex_lock(philo->fork_r);
		ft_print(philo, "has taken a fork 🍴");
		pthread_mutex_lock(philo->fork_l);
		ft_print(philo, "has taken a fork 🍴");
		ft_increase_eat(philo);
		philo->last_meal = ft_current_time();
		ft_print(philo, "is eating 🍝");
		ft_msleep(philo->data->time_to_eat, philo->data);
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_unlock(philo->fork_l);
		ft_print(philo, "is sleeping 💤");
		ft_msleep(philo->data->time_to_sleep, philo->data);
		ft_print(philo, "is thinking 💭");
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
		if (ft_current_time() - philos[i].last_meal >= data->time_to_die)
			return (ft_print(&philos[i], "died 💀"), ft_set_died(data), NULL);
		if (i == 0)
			count = 0;
		if (ft_get_eat(&philos[i]) >= data->must_eat)
			count++;
		if (count == data->nb_philos && data->must_eat != -1)
			return (ft_set_died(data), NULL);
		i = (i + 1) % data->nb_philos;
	}
	return (NULL);
}

void	ft_print(t_philo *philo, char *is_doing)
{
	if (!ft_check_died(philo->data))
		printf("%lums\t%d %s\n", ft_elapsed_time(philo->data->time),
			philo->id + 1, is_doing);
}
