#ifdef TEST

#include "unity.h"

#include "philo.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void	test_has_returned_executed_philo(){
	TEST_ASSERT_EQUAL_STRING_MESSAGE("executed philo", should_return_executed_philo(),"has not passed!");
}

#endif // TEST
