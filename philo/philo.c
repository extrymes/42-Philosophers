/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:24:47 by sabras            #+#    #+#             */
/*   Updated: 2024/08/10 16:29:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (printf(RED "Usage:\n\t./philo <nb_of_philos> <time_to_die> \
<time_to_eat> <time_to_sleep> <nb_of_each_philo_to_eat>\n" RESET), 1);
	data.nb_of_philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data.nb_of_each_philo_to_eat = ft_atoi(av[5]);
	ft_init_philos(data.nb_of_philos);
	return (0);
}
