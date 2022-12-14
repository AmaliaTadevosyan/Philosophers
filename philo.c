/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:45 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/14 16:29:47 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_data)
{
	long long	cur_time;
	t_data		*data;
	
	data = philo_data;
	cur_time = get_time();
	if (data->philo_index % 2)
		ft_usleep(data->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(&data->right_fork);
		printf("%llu, %d has teken right fork\n", get_time() - cur_time, data->philo_index);
		pthread_mutex_lock(&data->left_fork);
		data->eat_count++;
		printf("%llu %d has teken left fork\n", get_time() - cur_time, data->philo_index);
		printf("%llu, %d is eating\n", get_time() - cur_time, data->philo_index);
		data->last_eat = get_time();
		ft_usleep(data->time_to_eat);
		pthread_mutex_unlock(&data->right_fork);
		pthread_mutex_unlock(&data->left_fork);
		printf("%llu, %d is sleeping\n", get_time() - cur_time, data->philo_index);
		ft_usleep(data->time_to_sleep);
	}
}

int	check_death(t_data data)
{
	long curr_time;

	curr_time = get_time();
	if (curr_time - data.last_eat > data.time_to_die)
	{
		pthread_mutex_lock(&data.print);
		printf("%ld %s %d %s\n", curr_time, "philo number", data.philo_index, "is dead");
		return (1);
	}
	return (0);
}

int	ft_finish(t_data *data)
{
	int	i;

	i = 0;
	if (data->num_must_eat < 0)
		return (0);
	while (i++ < data->philo_count)
	{
		pthread_mutex_lock(&data[i].eat);
		if (data[i].eat_count < data[i].num_must_eat)
		{
			pthread_mutex_unlock(&data[i].eat);
			return (0);
		}
		pthread_mutex_unlock(&data[i].eat);
	}
	return (1);
}
