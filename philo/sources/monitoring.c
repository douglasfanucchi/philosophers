/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:35:07 by dfanucch          #+#    #+#             */
/*   Updated: 2023/03/17 20:25:50 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_has_died(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->is_over_mutex);
	printf("%ld %d died\n", get_time(philo->start), philo->pos);
	table->is_over = 1;
	pthread_mutex_unlock(&table->is_over_mutex);
}

static void	dinner_is_over(t_table *table)
{
	pthread_mutex_lock(&table->is_over_mutex);
	table->is_over = 1;
	pthread_mutex_unlock(&table->is_over_mutex);
}

char	some_philo_should_eat(t_table *table)
{
	t_philo	*philo;
	size_t	i;

	i = 0;
	while (i < table->philo_count)
	{
		philo = table->philosophers[i];
		pthread_mutex_lock(&philo->current_meal_mutex);
		if (philo->current_meal != philo->meals_count)
		{
			pthread_mutex_unlock(&philo->current_meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->current_meal_mutex);
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	size_t	i;

	table = arg;
	if (table->philo_count == 1)
		return (NULL);
	while (some_philo_should_eat(table))
	{
		i = -1;
		while (++i < table->philo_count)
		{
			philo = table->philosophers[i];
			pthread_mutex_lock(&philo->last_meal_mutex);
			if (get_time(philo->start) > philo->last_meal + philo->time_to_die)
			{
				pthread_mutex_unlock(&philo->last_meal_mutex);
				philo_has_died(philo, table);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->last_meal_mutex);
		}
		usleep(1);
	}
	dinner_is_over(table);
	return (NULL);
}
