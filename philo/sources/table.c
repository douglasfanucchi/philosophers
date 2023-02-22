/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:23:58 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/21 20:23:58 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static t_fork	**get_forks(size_t philo_count)
{
	size_t	i;
	t_fork	**forks;

	forks = malloc(sizeof(t_fork **) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		forks[i] = malloc(sizeof(t_fork));
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

void	clean_table(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(table->forks[i]);
		free(table->forks[i]);
		i++;
	}
	free(table->forks);
	i = 0;
	while (i < table->philo_count)
		delete_philo(table->philosophers[i++]);
	free(table->philosophers);
}

void	serve_table(t_table *table, char **args)
{
	time_t	time_die;
	time_t	time_eat;
	time_t	time_sleep;
	t_fork	*prev_fork;
	size_t	i;

	table->started_time = get_timestamp();
	table->philo_count = ft_atoi(args[0]);
	table->philosophers = malloc(sizeof(t_philo *) * table->philo_count);
	time_die = ft_atoi(args[1]);
	time_eat = ft_atoi(args[2]);
	time_sleep = ft_atoi(args[3]);
	table->forks = get_forks(table->philo_count);
	prev_fork = table->forks[table->philo_count - 1];
	i = 0;
	while (i < table->philo_count)
	{
		table->philosophers[i] = new_philo(i + 1, prev_fork, table->forks[i]);
		if (args[4])
			table->philosophers[i]->meals_count = ft_atoi(args[4]);
		set_times(table->philosophers[i], time_die, time_eat, time_sleep);
		prev_fork = table->forks[i];
		i++;
	}
}
