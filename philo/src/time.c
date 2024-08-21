/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:18:28 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 22:31:56 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	ft_curr_time(void)
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

unsigned long	ft_elap_time(unsigned long time)
{
	return (ft_curr_time() - time);
}

int	ft_msleep(unsigned long ms, t_data *data)
{
	unsigned long	start;

	start = ft_curr_time();
	while ((ft_curr_time() - start) < ms)
	{
		if (ft_check_died(data))
			break ;
		usleep(500);
	}
	return (0);
}
