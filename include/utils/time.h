#ifndef TIME_H
# define TIME_H
# include "struct.h"
# ifndef time_t
typedef	long time_t;
# endif
time_t	get_time_ms(void);
void	p_sleep(time_t duration);
#endif // TIME_H
