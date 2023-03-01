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

static void	initial_state(t_philo *philo)
{
	philo->last_meal = get_time(*philo->table);
	if (philo->pos % 2 == 0)
		usleep(to_microsec(philo->time_to_eat));
	change_state(philo, EATING);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	initial_state(philo);
	while (philo->current_meal != philo->meals_count)
	{
		if (is_dinner_over(philo->table))
		{
			if (philo->state == EATING)
			{
				pthread_mutex_unlock(philo->forks[0]);
				pthread_mutex_unlock(philo->forks[1]);
			}
			return (NULL);
		}
		if (philo->state == EATING)
		{
			philo->current_meal += 1;
			change_state(philo, SLEEPING);
		}
		else if (philo->state == SLEEPING)
			change_state(philo, THINKING);
		else
			change_state(philo, EATING);
	}
	return (NULL);
}

void	delete_philo(t_philo *philo)
{
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
	return (philo);
}
