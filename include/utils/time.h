#ifndef TIME_H
# define TIME_H
# include "struct.h"
# ifndef time_t
typedef	long time_t;
# endif
time_t	get_time_ms(void);
#endif // TIME_H
