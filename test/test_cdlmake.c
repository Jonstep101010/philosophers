#ifdef TEST

#include "unity.h"

#include "cdlmake.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void    test_has_printed(){
    TEST_ASSERT_EQUAL_STRING_MESSAGE("executed philo", should_print_executed(), "has not passed!");
}

#endif // TEST
