/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:06:32 by amtadevo          #+#    #+#             */
/*   Updated: 2022/12/14 16:35:21 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_data
{
	pthread_t		id;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				philo_index;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	long			last_eat;
	long			start_time;
	long			stop_time;
	int				eat_count;
}	t_data;

void		ft_usleep(int ms);
long int	get_time(void);
int			check_args(char **argv);
void		args_parsing(char **argv, int argc, t_data *data);
void		init_mutex(pthread_mutex_t *forks, int forks_count);
void		init_philo(t_data *data, pthread_mutex_t *forks, char **argv);
int			ft_atoi(const char *str);
void		*routine(void *data);
int			check_death(t_data data);
int			ft_finish(t_data *data);

#endif