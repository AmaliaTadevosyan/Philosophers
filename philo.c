/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:45 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/10 16:58:57 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *philo_data)
{
	long	curr_time;
	t_data	data;

	philo = philo_data;
	if (data->philo_index % 2)
		ft_usleep(200);
	while (1)
	{
		pthred_mutex_lock(data->left_fork);
		curr_time = get_time();
	}
}

int	check_dead(t_data data)
{
	long	curr_time;

	curr_time = get_time();
	if (curr_time - data.last_eat > data.time_to_die)
	{
		printf("%s %d %s\n", "philo number", data.philo_index, "died");
		return (1);
	}
	return (0);
}