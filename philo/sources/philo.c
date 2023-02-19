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
	free(philo);
}

t_philo	*new_philo(int pos, pthread_mutex_t *l_fork, pthread_mutex_t *r_fork)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->pos = pos;
	philo->forks[0] = l_fork;
	philo->forks[1] = r_fork;
	philo->state = -1;
	return (philo);
}
