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

typedef struct s_philo {
	int				pos;
	int				state;
	t_fork			**forks;
	pthread_t		thread;
	struct s_table	*table;
	time_t			last_meal;
}	t_philo;

typedef struct s_table {
	char	is_over;
	t_philo	**philosophers;
	time_t	started_time;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	time_to_die;
	int		meals_count;
}	t_table;

time_t	get_timestamp(void);
time_t	to_microsec(time_t ms);
time_t	get_time(t_table table);
long	ft_atoi(const char *nptr);
void	delete_philo(t_philo *philo);
t_philo	*new_philo(int pos, t_fork *left_fork, t_fork *right_fork);

#endif
