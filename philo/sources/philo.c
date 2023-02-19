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

void	delete_philo(t_philo *philo)
{
	free(philo->forks);
	free(philo);
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
	return (philo);
}
