/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:28:12 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/22 18:45:22 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(data[i].left_fork);
		pthread_mutex_destroy(data[i].right_fork);
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

	if ((argc == 5 || argc == 6) && check_args(argv) == 1)
	{
		data = malloc(sizeof(*data) * ft_atoi(argv[1]));
		forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
		init_mutex(forks, ft_atoi(argv[1]));
		init_philo(data, forks, argv);
		while (1)
		{
			i = 0;
			while (i < data->philo_count)
			{
				if (check_death(&data[i]))
				{
					ft_free(data, forks);
					return (0);
				}
				i++;
			}
		}
	}
	printf("Invalid arguments!\n");
}
