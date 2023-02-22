/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:03:39 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/21 22:03:39 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	print_has_taken_fork(t_philo *philo)
{
	print_state(philo, "has taken a fork");
}

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->is_over_mutex);
	if (!philo->table->is_over)
		printf("%ld %d %s\n", get_time(*philo->table), philo->pos, str);
	pthread_mutex_unlock(&philo->table->is_over_mutex);
}

void	change_state(t_philo *philo, int state)
{
	if (state == EATING)
	{
		pthread_mutex_lock(philo->forks[0]);
		print_has_taken_fork(philo);
		pthread_mutex_lock(philo->forks[1]);
		print_has_taken_fork(philo);
		philo->last_meal = get_time(*philo->table);
		philo->state = EATING;
		print_state(philo, "is eating");
		usleep(to_microsec(philo->time_to_eat));
		return ;
	}
	if (state == SLEEPING)
	{
		pthread_mutex_unlock(philo->forks[0]);
		pthread_mutex_unlock(philo->forks[1]);
		print_state(philo, "is sleeping");
		philo->state = SLEEPING;
		usleep(to_microsec(philo->time_to_sleep));
		return ;
	}
	philo->state = THINKING;
	print_state(philo, "is thinking");
}
