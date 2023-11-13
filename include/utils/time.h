// #ifndef TIME_H
#ifndef NULL
#define NULL ((void*)0)
#endif
#define TIME_H
# ifndef time_t
typedef	long time_t;
# endif
// #include "struct.h"
time_t	get_time_ms(void);
void	p_sleep(time_t duration);
typedef struct s_table t_table;
time_t	timestamp(t_table *table);
// #endif // TIME_H
