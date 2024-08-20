/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:47:54 by sabras            #+#    #+#             */
/*   Updated: 2024/08/20 14:45:16 by sabras           ###   ########.fr       */
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
			return (ft_print_error("arguments must be positive numbers"), 0);
		s++;
	}
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		if (n > 2147483647)
			return (ft_print_error("arguments too big"), 0);
		s++;
	}
	if (n == 0)
		return (ft_print_error("arguments must be positive numbers"), 0);
	return (n);
}

void	ft_dest_mutex(int nb_philos, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_destroy(philos[i].fork_r);
		pthread_mutex_destroy(philos[i].fork_l);
		i++;
	}
}

unsigned long	ft_current_time(void)
{
	struct timeval	time;
	unsigned long	total;
	unsigned long	sec;
	unsigned long	u_sec;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000);
	u_sec = (time.tv_usec / 1000);
	total = sec + u_sec;
	return (total);
}

unsigned long	ft_elapsed_time(unsigned long time)
{
	return (ft_current_time() - time);
}

void	ft_print_error(char *s)
{
	printf(RED "Error: %s\n" RESET, s);
}
