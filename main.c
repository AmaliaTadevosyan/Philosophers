#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			*data;
	pthread_mutex_t	*forks;
	int				i;
	int				count;

	if (argc >= 5 && argc <= 6)
	{
		count = ft_atoi(argv[1]);
		data = malloc(sizeof(data) * count);
		forks = mallo(sizeof(pthread_mutex_t) * count);
		init_mutex(forks, count);
		//init philo;
	}
}