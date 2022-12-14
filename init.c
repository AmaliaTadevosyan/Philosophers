/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:53:32 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/22 18:10:58 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data, char **argv, int *i)
{
		data[*i].philo_index = *i;
		data[*i].philo_count = ft_atoi(argv[1]);
		data[*i].time_to_die = ft_atoi(argv[2]);
		data[*i].time_to_eat = ft_atoi(argv[3]);
		data[*i].time_to_sleep = ft_atoi(argv[4]);
}

void	init_philo(t_data *data, pthread_mutex_t *forks, char **argv)
{
	int				i;
	struct timeval	start;

	i = -1;
	gettimeofday(&start, NULL);
	while (++i < ft_atoi(argv[1]))
	{
		init(data, argv, &i);
		data[i].last_eat = start.tv_sec * 1000 + start.tv_usec / 1000;
		data[i].left_fork = &forks[i];
		data[i].right_fork = &(forks[(i + 1) % data[i].philo_count]);
		data[i].eat_count = 0;
		if (argv[5])
			data[i].num_must_eat = ft_atoi(argv[5]);
		else
			data[i].num_must_eat = -1;
		data[i].start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
		pthread_create(&data[i].id, NULL, (void *) routine, &data[i]);
		pthread_detach(data[i].id);
	}
}

void	init_mutex(pthread_mutex_t *forks, int forks_count)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < forks_count)
	{
		error = pthread_mutex_init(&forks[i], NULL);
		if (error)
		{
			printf("Error mutex number %d\n", error);
		}
		i++;
	}
}
