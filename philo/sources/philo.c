/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:47:44 by dfanucch          #+#    #+#             */
/*   Updated: 2023/03/17 20:26:09 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time(philo->start);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (philo->table->philo_count == 1)
	{
		print_has_taken_fork(philo);
		usleep(to_microsec(philo->time_to_die));
		philo_has_died(philo, philo->table);
	}
	if (philo->pos % 2 == 0)
		usleep(to_microsec(philo->time_to_eat));
	while (!is_dinner_over(philo->table))
	{
		change_state(philo, EATING);
		pthread_mutex_lock(&philo->current_meal_mutex);
		philo->current_meal += 1;
		pthread_mutex_unlock(&philo->current_meal_mutex);
		if (philo->current_meal == philo->meals_count)
			return (NULL);
		change_state(philo, SLEEPING);
		change_state(philo, THINKING);
		usleep(1);
	}
	return (NULL);
}

void	delete_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->last_meal_mutex);
	pthread_mutex_destroy(&philo->current_meal_mutex);
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
	philo->last_meal = 0;
	pthread_mutex_init(&philo->last_meal_mutex, NULL);
	pthread_mutex_init(&philo->current_meal_mutex, NULL);
	return (philo);
}
