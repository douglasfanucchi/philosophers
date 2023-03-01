/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:40:19 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/19 10:40:19 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

enum e_philo_state {
	EATING,
	SLEEPING,
	THINKING
};

typedef pthread_mutex_t	t_fork;

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo {
	int				pos;
	int				state;
	t_fork			**forks;
	pthread_t		thread;
	struct s_table	*table;
	time_t			last_meal;
	void			*(*routine)(void *arg);
	int				meals_count;
	int				current_meal;
	t_mutex			current_meal_mutex;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
}	t_philo;

typedef struct s_table {
	t_mutex	is_over_mutex;
	char	is_over;
	size_t	philo_count;
	t_philo	**philosophers;
	time_t	started_time;
	t_fork	**forks;
}	t_table;

time_t	get_timestamp(void);
time_t	to_microsec(time_t ms);
time_t	get_time(t_table table);
long	ft_atoi(const char *nptr);
void	delete_philo(t_philo *philo);
t_philo	*new_philo(int pos, t_fork *left_fork, t_fork *right_fork);
void	serve_table(t_table *table, char **args);
void	clean_table(t_table *table);
void	set_times(t_philo *philo, time_t time_to_die, time_t time_to_eat,
			time_t time_to_sleep);
void	change_state(t_philo *philo, int state);
void	print_state(t_philo *philo, char *str);
void	*monitoring(void *arg);
char	is_dinner_over(t_table *table);

#endif
