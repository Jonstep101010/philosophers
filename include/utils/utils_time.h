#ifndef UTILS_TIME_H
# define UTILS_TIME_H

#include <sys/time.h>
#include <time.h>
#include <stddef.h>
#include "struct.h"

time_t	get_time_ms(void);
void	p_sleep(time_t duration);
typedef struct s_table t_table;
time_t	timestamp(t_table *table);
#endif // TIME_H
