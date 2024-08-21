/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:04:07 by sabras            #+#    #+#             */
/*   Updated: 2024/08/21 11:57:47 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_set_died(t_data *data)
{
	pthread_mutex_lock(&data->died_lock);
	data->is_died = 1;
	pthread_mutex_unlock(&data->died_lock);
}

int	ft_check_died(t_data *data)
{
	int	is_died;

	is_died = 0;
	pthread_mutex_lock(&data->died_lock);
	if (data->is_died)
		is_died = 1;
	pthread_mutex_unlock(&data->died_lock);
	return (is_died);
}
