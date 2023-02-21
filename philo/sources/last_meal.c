/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_meal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:50:45 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/21 08:50:48 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

time_t	get_last_meal_time(t_last_meal last_meal)
{
	time_t	time;

	pthread_mutex_lock(&last_meal.mutex);
	time = last_meal.time;
	pthread_mutex_unlock(&last_meal.mutex);
	return (time);
}

void	set_last_meal_time(t_last_meal *last_meal, time_t time)
{
	pthread_mutex_lock(&last_meal->mutex);
	last_meal->time = time;
	pthread_mutex_unlock(&last_meal->mutex);
}
