/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:45 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/22 18:50:21 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_data *data, long *cur_time)
{
	pthread_mutex_lock(data->left_fork);
	printf("%lu %d left fork\n", get_time() - *cur_time,
		data->philo_index);
	pthread_mutex_lock(data->right_fork);
	data->eat_count++;
	printf("%lu %d right fork\n", get_time() - *cur_time,
		data->philo_index);
	printf("%lu %d is eating 🥦\n", get_time() - *cur_time,
		data->philo_index);
	data->last_eat = get_time();
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
	printf("%ld %s %d %s\n", get_time() - *cur_time, "philo",
		data->philo_index, "is sleeping");
	ft_usleep(data->time_to_sleep);
	printf("%ld %s %d %s\n", get_time() - *cur_time, "philo",
		data->philo_index, "is thinking");
}

void	*routine(t_data *data)
{
	long		cur_time;

	cur_time = get_time();
	if (data->philo_index % 2 == 0)
		ft_usleep(data->time_to_eat);
	while (data->num_must_eat)
	{
		print_philo(data, &cur_time);
		if (data->num_must_eat != -1)
			data->num_must_eat--;
	}
	return (NULL);
}

int	check_death(t_data *data)
{
	long	curr_time;

	curr_time = get_time();
	if (curr_time - data->last_eat > data->time_to_die)
	{
		printf("%ld %s %d %s\n", get_time() - data->last_eat, "philo",
			data->philo_index, "is dead");
		return (1);
	}
	if (data->num_must_eat == 0)
		return (1);
	return (0);
}
