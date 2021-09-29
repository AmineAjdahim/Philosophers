/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:12:06 by majdahim          #+#    #+#             */
/*   Updated: 2021/09/29 16:12:10 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	prnterror(char *error, int exit)
{
	write(1, error, ft_strlen(error));
	return (exit);
}

void	get_data(char **av)
{
	g_data.nb_philo = ft_atoi(av[1]);
	g_data.tm_die = ft_atoi(av[2]);
	g_data.tm_eat = ft_atoi(av[3]);
	g_data.tm_sleep = ft_atoi(av[4]);
	if (av[5])
		g_data.nb_to_eat = ft_atoi(av[5]);
}
