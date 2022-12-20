/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:38 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/20 18:38:47 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time()
{
	struct timeval	curr_time;
	long int		ret;

	gettimeofday(&curr_time, NULL);
	ret = (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000) ;
	return (ret);
}

void	ft_usleep(int ms)
{
	struct timeval	now;
	struct timeval	start;
	
	gettimeofday(&start, 0);
	gettimeofday(&now, 0);
	while ((now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000 < ms)
	{
		usleep(50);
		gettimeofday(&now, 0);
	}
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
		if (ft_atoi(argv[i]) <= 0)
			return (0);
	}
	return (1);
}
