#ifdef TEST

#include "unity.h"

#include "struct.h"
#include "time.h"

void setUp(void)
{
}

void tearDown(void)
{
}

#include <sys/time.h>
void test_get_time_ms_returnsval(void)
{
    // TEST_IGNORE_MESSAGE("Need to Implement time");
	TEST_ASSERT_EQUAL_UINT64(time(NULL), get_time_ms()/1000);
	TEST_ASSERT_UINT64_WITHIN(2, time(NULL), get_time_ms()/1000);
}


#endif // TEST
