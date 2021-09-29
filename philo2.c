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

int	parsing(int ac, char **av)
{
	int		i;
	int		j;

	if (ac != 5 && ac != 6)
	{
		prnterror("Error: syntax\n", 0);
		return (0);
	}
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Error: syntax2\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
