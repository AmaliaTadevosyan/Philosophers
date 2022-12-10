/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:28:12 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/10 16:37:08 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			*data;
	pthread_mutex_t	*forks;
	int				i;
	int				count;
	int				flag;
	
	flag = check_args(argv);
	if (argc >= 5 && argc <= 6 && flag)
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
				if (check_dead())
				{
					printf("Philo is died!\n");
					return (0);
				}
				i++;
			}
		}
	}
	printf("Invalid arguments!\n");
}