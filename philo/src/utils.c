/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:47:54 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 22:31:56 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *s)
{
	int long	n;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			return (ft_error("arguments must be positive numbers"), 0);
		s++;
	}
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		if (n > 2147483647)
			return (ft_error("arguments too big"), 0);
		s++;
	}
	if (n == 0)
		return (ft_error("arguments must be positive numbers"), 0);
	return (n);
}

void	ft_dest_mutexes(t_data *data, t_philo *philos, int nb_philos)
{
	int	i;

	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->died_lock);
	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_destroy(philos[i].fork_r);
		pthread_mutex_destroy(philos[i].fork_l);
		pthread_mutex_destroy(&philos[i].eat_lock);
		i++;
	}
}

void	ft_print(t_philo *philo, char *is_doing)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (!ft_check_died(philo->data))
		printf("%lums\t%d %s\n", ft_elap_time(philo->data->time),
			philo->id + 1, is_doing);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	ft_error(char *s)
{
	printf(RED "Error: %s\n" RESET, s);
}
