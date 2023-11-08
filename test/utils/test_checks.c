#include "unity.h"

#include "struct.h"
#include "checks.h"

void setUp(void)
{
}

void tearDown(void)
{
}

#include <stdlib.h>
void test_isdigit()
{
	for (int i = 0; i <= 9; i++) {
		TEST_ASSERT_EQUAL(true, ft_isdigit(i + '0'));
	}
	for (int i = 10; i <= 127; i++) {
		TEST_ASSERT_EQUAL(false, ft_isdigit(i + '0'));
	}
}
