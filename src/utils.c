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
	int			sign;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		if ((n * sign > 2147483647) || (n * sign < -2147483648))
			return (ft_throw_error("bad arguments"), 0);
		s++;
	}
	return (n * sign);
}

void	ft_throw_error(char *s)
{
	printf(RED "Error: %s\n" RESET, s);
	exit(1);
}
