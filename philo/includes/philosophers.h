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

enum e_philo_state {
	EATING,
	SLEEPING,
	THINKING
};

typedef struct s_philo {
	int				pos;
	int				state;
	pthread_mutex_t	**forks;
}	t_philo;

typedef struct s_table {
	t_philo	**philosophers;
	time_t	started_time;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	time_to_think;
	int		meals_count;
}	t_table;

time_t	get_timestamp(void);
time_t	to_microsec(time_t ms);
time_t	get_time(t_table table);

#endif
