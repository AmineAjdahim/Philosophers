/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:28:40 by majdahim          #+#    #+#             */
/*   Updated: 2021/09/29 16:33:04 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int		id;
	int		nbr_time_eat;
	long	last_time_eat;

}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				tm_eat;
	int				tm_die;
	int				tm_sleep;
	int				nb_to_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_t		*philos;
	t_philo			*profile;
}	t_data;

t_data	g_data;

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	timeprnt(char *str, int id);
long	time_now_micro(void);
int		prnterror(char *error, int exit);
void	get_data(char **av);

#endif
