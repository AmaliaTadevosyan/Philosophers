/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:45 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/20 18:44:13 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action(t_data *data, long *curr_time)
{
	*curr_time = get_time(data->start_time);
	printf("%ld %s %d %s\n", *curr_time, "philo",
		data->philo_index, "is sleeping");
	ft_usleep(data->time_to_sleep);
	*curr_time = get_time(data->start_time);
	printf("%ld %s %d %s\n", *curr_time, "philo",
		data->philo_index, "is thinking");
}

void	*routine(t_data *data)
{
	long		cur_time;
	
	cur_time = get_time();
	if (data->philo_index % 2 == 0)
		ft_usleep(data->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(data->left_fork);
		printf("%lu, %d left fork\n", get_time() - cur_time,
			data->philo_index);
		pthread_mutex_lock(data->right_fork);
		data->eat_count++;
		printf("%lu %dright fork\n", get_time() - cur_time,
			data->philo_index);
		// pthread_mutex_lock(&data->eat);
		// pthread_mutex_unlock(&data->eat);
		// pthread_mutex_lock(&data->print);
		printf("%lu, %d is eating\n", get_time() - cur_time,
			data->philo_index);
		data->last_eat = get_time();
		printf("%ld>>>>>>>>>>>>\n", data->last_eat);
		// pthread_mutex_unlock(&data->print);
		ft_usleep(data->time_to_eat);
		pthread_mutex_unlock(data->left_fork);
		pthread_mutex_unlock(data->right_fork);
		printf("%ld %s %d %s\n", get_time() - cur_time, "philo",
		data->philo_index, "is sleeping");
		// action(data, &cur_time);
	}
}

int	check_death(t_data data)
{
	long	curr_time;

	curr_time = get_time(data.start_time);
	if (curr_time - data.last_eat > data.time_to_die)
	{
		// pthread_mutex_lock(&data.print);
		printf("%ld %s %d %s\n", curr_time, "philo",
			data.philo_index, "is dead");
		return (1);
	}
	return (0);
}

int	ft_finish(t_data *data)
{
	int	i;

	i = -1;
	if (data->num_must_eat < 0)
		return (0);
	while (++i < data->philo_count)
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
