/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:38:43 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/19 10:38:43 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static char	has_valid_numbers(char **args)
{
	while (*args)
	{
		if (ft_atoi(*args) <= 0)
			return (0);
		args++;
	}
	return (1);
}

static char	is_valid(int argc, char **args)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!has_valid_numbers(args))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!is_valid(argc, argv + 1))
	{
		write(2, "Invalid parameters\n", 19);
		return (1);
	}
}
