/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:45 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/13 16:29:01 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_data *data)
{
	long long	cur_time;
	
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

int	check_dead(t_data *data)
{
	int			i;
	long long	time;
	int			count;
	
	count = 0;
	i = 0;
	while (i < data->philo_count)
	{
		time = get_time();
		if (data->eat_count == data->num_must_eat)
		{
			
		}
	}
}

int	ft_finish(t_data *data)
{
	int	i;

	i = 0;
	if (data->num_must_eat < 0)
		return (0);
	while (i++ < data->philo_count)
	{
		thread_mutex_unlock(&data[i].time_to_eat);	
	}
}