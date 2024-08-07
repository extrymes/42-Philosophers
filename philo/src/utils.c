/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:47:54 by sabras            #+#    #+#             */
/*   Updated: 2024/07/29 13:42:25 by sabras           ###   ########.fr       */
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
