/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:01 by afontan           #+#    #+#             */
/*   Updated: 2025/03/25 15:48:26 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define MAX_PHILO 300

typedef struct s_philos
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	int				*dead;
	size_t			last_meal;
	size_t			start_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	struct s_table	*table;

}	t_philos;

typedef struct s_table
{
	pthread_mutex_t	forks[MAX_PHILO];

	size_t			time_to_die;
	size_t			time_to_sleep;
	int				dead_flag;
	int				time_to_eat;
	int				nb_of_philo;
	int				nb_of_eat;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	t_philos		*philos;
}	t_table;

/**========================================================================
 *                        		    THREAD
 *========================================================================**/

size_t		actual_time(void);
void		eat(t_philos *philo);
void		sleeping(t_philos *philo);
void		thinking(t_philos *philo);
void		*monitor(void *ptr);
int			dead_loop(t_philos *philo);
int			create_thread(t_table *table);

/**========================================================================
 *                      		     INIT
 *========================================================================**/

void		init_table(t_table *table, t_philos *philos);
void		init_forks(t_table *table, int nb_of_philo);
void		init_philos(t_table *table, char **av);

/**========================================================================
 *                        			 UTILS
 *========================================================================**/

int			ft_atoi(char *str);
int			ft_usleep(size_t millisecond);
//void		print_status(t_table table, t_philos *philo);
void		print_mess(char *str, t_philos *philo, int philo_num);
void		ft_error(char *str);
void		destroy_all(char *str, t_table *table);

#endif