/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:35:17 by dfanucch          #+#    #+#             */
/*   Updated: 2023/02/19 11:35:19 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static char	ft_isspace(char c)
{
	return (
		c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
	);
}

long	ft_atoi(const char *nptr)
{
	long	signal;
	long	result;

	signal = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		signal *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	return (result * signal);
}
