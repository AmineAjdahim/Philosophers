/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:12:42 by majdahim          #+#    #+#             */
/*   Updated: 2021/09/29 16:28:18 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				b;
	size_t			c;

	i = 0;
	b = 1;
	c = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
		|| (str[i] == '\n' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		b = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		if (c > 9223372036854775807 && b == -1)
			return (0);
		else if (c > 9223372036854775807 && b == 1)
			return (-1);
		i++;
	}
	return (c * b);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	time_now_micro(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (ms);
}

void	timeprnt(char *str, int id)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + tv.tv_usec / 1000;
	printf("%ld %d %s\n", ms, id, str);
}
