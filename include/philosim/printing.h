#ifndef PRINTING_H
# define PRINTING_H

# include "struct.h"
#ifndef TEST
void	print_message(t_philo *philo, char *msg);
#else
time_t	mock_get_time_ms(void);
unsigned long	mock_timestamp(t_table *table);
void	mock_print_message(t_philo *philo, char *msg);
#endif
#endif // PRINTING_H
