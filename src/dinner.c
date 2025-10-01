#include "includes/philosophers.h"

static void eat(t_philo *philo)
{
	
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	wait_all_thread(philo->table);



	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break;
		
		eat(philo);


		write_status(SLEEPING, philo);
		precise_usleep(philo->table->time_to_sleep, philo->table);
	

		thinking(philo);
	}


	return (NULL);
}

void dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		;
	else
	{
		while (++i < table->philo_nbr)
			safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	}
	table->start_simulation = gettime(MILLISECOND);
	set_bool(&table->table_mutex, table->all_threads_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	
}