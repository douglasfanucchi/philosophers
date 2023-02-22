/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:47:44 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/19 11:47:45 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	return (philo);
}

void	delete_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->last_meal.mutex);
	free(philo->forks);
	free(philo);
}

void	set_times(t_philo *philo, time_t time_to_die, time_t time_to_eat,
		time_t time_to_sleep)
{
	philo->time_to_die = time_to_die;
	philo->time_to_eat = time_to_eat;
	philo->time_to_sleep = time_to_sleep;
}

t_philo	*new_philo(int pos, t_fork *left_fork, t_fork *right_fork)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->forks = malloc(sizeof(t_fork) * 2);
	philo->pos = pos;
	philo->forks[0] = left_fork;
	philo->forks[1] = right_fork;
	philo->state = -1;
	philo->meals_count = -1;
	philo->current_meal = 0;
	philo->routine = routine;
	pthread_mutex_init(&philo->last_meal.mutex, NULL);
	return (philo);
}
