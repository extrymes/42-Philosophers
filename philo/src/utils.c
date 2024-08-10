/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:47:54 by sabras            #+#    #+#             */
/*   Updated: 2024/08/10 16:27:13 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_philos(int nb_of_philos)
{
	t_philo	*philos;
	int		i;

	philos = malloc(nb_of_philos * sizeof(t_philo));
	if (!philos)
		ft_throw_error("failed to allocate memory for philos");
	i = 0;
	while (i < nb_of_philos)
	{
		philos[i].id = i;
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			ft_throw_error("failed to create thread");
		i++;
	}
	i = 0;
	while (i < nb_of_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			ft_throw_error("failed to join thread");
		i++;
	}
}

int	ft_atoi(char *s)
{
	int long	n;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			return (ft_throw_error("arguments must be positive numbers"), 0);
		s++;
	}
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		if (n > 2147483647)
			return (ft_throw_error("arguments too big"), 0);
		s++;
	}
	if (n == 0)
		return (ft_throw_error("arguments must be positive numbers"), 0);
	return (n);
}

void	ft_throw_error(char *s)
{
	printf(RED "Error: %s\n" RESET, s);
	exit(1);
}
