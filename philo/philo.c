/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:24:47 by sabras            #+#    #+#             */
/*   Updated: 2024/08/20 11:41:14 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_init_philos(t_data *data);

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if (ac != 5 && ac != 6)
		return (printf(RED "Usage:\n\t./philo <nb_philos> <time_to_die> \
<time_to_eat> <time_to_sleep> <nb_of_each_philo_to_eat>\n" RESET), 1);
	data.nb_philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data.nb_of_each_philo_to_eat = ft_atoi(av[5]);
	data.must_eat = 0;
	data.total_eat = 0;
	data.time = ft_current_time();
	philos = ft_init_philos(&data);
	return (0);
}

t_philo	*ft_init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(data->nb_philos * sizeof(t_philo));
	if (!philos)
		ft_throw_error("failed to allocate memory for philos");
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].id = i;
		philos[i].eat = 0;
		philos[i].fork_r = &philos[(philos[i].id + 1) % data->nb_philos].fork_m;
		philos[i].fork_l = &philos[i].fork_m;
		pthread_mutex_init(philos[i].fork_r, NULL);
		pthread_mutex_init(philos[i].fork_l, NULL);
		philos[i].data = data;
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			ft_throw_error("failed to create thread");
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			ft_throw_error("failed to join thread");
		i++;
	}
	return (philos);
}
