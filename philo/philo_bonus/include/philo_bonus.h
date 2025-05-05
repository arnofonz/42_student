/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:01 by afontan           #+#    #+#             */
/*   Updated: 2025/03/26 09:25:05 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int				id;
	int				meals;
	pid_t			pid;
	size_t			last_meal;
	pthread_t		check_monitor;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int		nb_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_of_eat;
	int		philo_stop;
	int		died;
	size_t	start_time;
	sem_t	*forks;
	sem_t	*print_lock;
	sem_t	*meal_lock;
	t_philo	*philos;
}	t_data;

/**========================================================================
 *                           	ROUTINE
 *========================================================================**/

void	routine(t_philo *philo);

/**========================================================================
 *                        		   INIT
 *========================================================================**/

void	init_data(t_data *data, int ac, char **av);
void	init_sem(t_data *data);

/**========================================================================
 *                     		      UTILS
 *========================================================================**/

void	ft_error(char *str);
int		ft_atoi(char *str);
size_t	actual_time(void);
int		ft_usleep(size_t millisecond);
void	print_mess(char *str, t_philo *philo, int philo_num);

#endif