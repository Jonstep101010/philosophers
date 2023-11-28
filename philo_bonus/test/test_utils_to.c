// #ifdef TEST

#include "unity.h"

#include "struct.h"
#include "utils_to.c"
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_utils_to_itoa(void) {
	for (int i = -1; ++i < 250;)
		TEST_ASSERT_EQUAL_STRING(ft_itoa(i), ft_itoa(i));
}

void	test_strjoin_basic(void) {
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "Hello ";
	s2 = "World!";
	s3 = "Hello World!";
	TEST_ASSERT_EQUAL_STRING(s3, ft_strjoin(s1, s2));
}

void	test_strjoin_empty(void) {
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "";
	s2 = "";
	s3 = "";
	TEST_ASSERT_EQUAL_STRING(s3, ft_strjoin(s1, s2));
}

void	test_strjoin_null(void) {
	TEST_ASSERT_NULL(ft_strjoin(NULL, "Hello"));
	TEST_ASSERT_NULL(ft_strjoin(NULL, NULL));
	TEST_ASSERT_NULL(ft_strjoin("World", NULL));
}

void	test_strjoin_number_id(void) {
	for (int i = -1; ++i < 250;)
		TEST_ASSERT_EQUAL_STRING(ft_itoa(i), ft_strjoin("", ft_itoa(i)));
	char buffer[50] = "Hello, ";
	strcat(buffer, "World!");
	TEST_ASSERT_EQUAL_STRING("Hello, World!", buffer);
	for (int i = -1; ++i < 250;) {
		char buffer[10] = "/sem_";
		strcat(buffer, ft_itoa(i));
		TEST_ASSERT_EQUAL_STRING(buffer, ft_strjoin("/sem_", ft_itoa(i)));
	}
}

void	test_something_need_to_implement(void) {
	TEST_IGNORE_MESSAGE("Need to implement");
}
// #endif // TEST
