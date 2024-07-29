/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:24:47 by sabras            #+#    #+#             */
/*   Updated: 2024/07/29 17:19:04 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_each_philo_to_eat;

	if (ac != 5 && ac != 6)
		return (ft_throw_error("bad arguments"), 1);
	nb_of_philos = ft_atoi(av[1]);
	time_to_die = ft_atoi(av[2]);
	time_to_eat = ft_atoi(av[3]);
	time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		nb_of_each_philo_to_eat = ft_atoi(av[5]);
	return (0);
}
