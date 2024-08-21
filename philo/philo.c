/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:24:47 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 11:22:00 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_init_data(t_data *data, char **av);
t_philo	*ft_init_philos(t_data *data);
int		ft_create_threads(t_data *data, t_philo *philos);

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if (ac != 5 && ac != 6)
		return (printf(RED "Usage:\n\t./philo <nb_philos> <time_to_die> \
<time_to_eat> <time_to_sleep> <nb_of_each_philo_to_eat>\n" RESET), 1);
	if (!ft_init_data(&data, av))
		return (1);
	philos = ft_init_philos(&data);
	if (!philos)
		return (1);
	ft_dest_mutexes(philos, data.nb_philos);
	free(philos);
	return (0);
}

int	ft_init_data(t_data *data, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_of_each_philo_to_eat = ft_atoi(av[5]);
	if (!data->nb_philos || !data->time_to_die || !data->time_to_eat
		|| !data->time_to_sleep || !data->nb_of_each_philo_to_eat)
		return (0);
	data->must_eat = 0;
	data->total_eat = 0;
	data->is_died = 0;
	data->time = ft_current_time();
	if (pthread_mutex_init(&data->print_lock, NULL) != 0
		&& pthread_mutex_init(&data->died_lock, NULL) != 0)
		return (ft_error("failed to init mutexes"), 0);
	return (1);
}

t_philo	*ft_init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(data->nb_philos * sizeof(t_philo));
	if (!philos)
		return (ft_error("failed to allocate memory for philos"), NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].id = i;
		philos[i].eat = 0;
		philos[i].fork_r = &philos[(philos[i].id + 1) % data->nb_philos].fork_m;
		philos[i].fork_l = &philos[i].fork_m;
		if (pthread_mutex_init(philos[i].fork_r, NULL) != 0
			&& pthread_mutex_init(philos[i].fork_l, NULL) != 0)
			return (ft_error("failed to init mutexes"), free(philos), NULL);
		philos[i].last_meal = ft_current_time();
		philos[i].data = data;
		i++;
	}
	if (!ft_create_threads(data, philos))
		return (free(philos), NULL);
	return (philos);
}

int	ft_create_threads(t_data *data, t_philo *philos)
{
	pthread_t	thread;
	int			i;

	if (pthread_create(&thread, NULL, checker, philos))
		return (ft_error("failed to create thread"), 0);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			return (ft_error("failed to create thread"), 0);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (ft_error("failed to join thread"), 0);
		i++;
	}
	return (1);
}
