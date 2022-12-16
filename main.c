/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:28:12 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/16 17:27:06 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data[i].left_fork);
		pthread_mutex_destroy(&data[i].right_fork);
		i++;
	}
	free(data);
	free(forks);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	pthread_mutex_t	*forks;
	int				i;
	int				count;
	
	if ((argc == 5 || argc == 6) && check_args(argv))
	{
		count = ft_atoi(argv[1]);
		data = malloc(sizeof(data) * count);
		forks = malloc(sizeof(pthread_mutex_t) * count);
		init_mutex(forks, count);
		init_philo(data, forks, argv);
		while (1)
		{
			i = 0;
			while (i < data->philo_count)
			{
				if (check_death(data[i]) || ft_finish(data))
				{
					ft_free(data, forks);
					printf("Stop th programm\n");
					pthread_mutex_unlock(&data[i].print);
					return (0);
				}
				i++;
			}
		}
	}
	printf("Invalid arguments!\n");
}
