/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:38:58 by majdahim          #+#    #+#             */
/*   Updated: 2021/09/29 17:57:22 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	iinit(void)
{
	int		i;

	i = 0;
	g_data.philos = malloc(sizeof(pthread_t) * g_data.nb_philo);
	if (!g_data.philos)
		return (-1);
	g_data.forks = malloc(sizeof(pthread_mutex_t) * g_data.nb_philo);
	while (i < g_data.nb_philo)
	{
		pthread_mutex_init(&g_data.forks[i], NULL);
		i++;
	}
	g_data.profile = malloc(sizeof(t_philo) * g_data.nb_philo);
	i = 0;
	while (i < g_data.nb_philo)
	{
		g_data.profile[i].id = i + 1;
		g_data.profile[i].nbr_time_eat = -1;
		g_data.profile[i].last_time_eat = 0;
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo		philo;

	philo = *(t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&g_data.forks[philo.id - 1]);
		timeprnt("take a forks L", philo.id);
		pthread_mutex_lock(&g_data.forks[philo.id % g_data.nb_philo]);
		timeprnt("take a forks R", philo.id);
		timeprnt("is eating", philo.id);
		g_data.profile[philo.id - 1].last_time_eat = time_now_micro();
		if (g_data.nb_to_eat)
			g_data.profile[philo.id - 1].nbr_time_eat += 1;
		usleep(g_data.tm_eat * 1000);
		pthread_mutex_unlock(&g_data.forks[philo.id - 1]);
		pthread_mutex_unlock(&g_data.forks[philo.id % g_data.nb_philo]);
		timeprnt("is sleeping", philo.id);
		usleep(g_data.tm_sleep * 1000);
		timeprnt("is thinking", philo.id);
	}
	return (NULL);
}

void	create_threads(void)
{
	int	i;

	i = 0;
	while (i < g_data.nb_philo)
	{
		g_data.profile[i].last_time_eat = time_now_micro();
		pthread_create(&g_data.philos[i], NULL, &routine, &g_data.profile[i]);
		usleep(100);
		i++;
	}
}

int	checkphilo(void)
{
	int		i;
	int		done;

	while (1)
	{
		done = 0;
		i = 0;
		while (i < g_data.nb_philo)
		{
			if ((time_now_micro() - g_data.profile[i].last_time_eat)
				> g_data.tm_die * 1000)
			{
				timeprnt("is die", i + 1);
				return (1);
			}
			if (g_data.profile[i].nbr_time_eat != -1
				&& g_data.profile[i].nbr_time_eat + 1 >= g_data.nb_to_eat)
				done++;
			i++;
		}
		usleep(100);
		if (done == g_data.nb_philo)
			return (1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	parsing(ac, av);
	get_data(av);
	iinit();
	create_threads();
	checkphilo();
	return (0);
}
