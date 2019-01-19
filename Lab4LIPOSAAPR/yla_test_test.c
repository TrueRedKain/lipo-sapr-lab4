#include "yla_test.h"

static int test_assertions()
{
	YLATEST_ASSERT_TRUE(1, "true assertion incorrect");
	YLATEST_ASSERT_FALSE(0, "false assertion incorrect");

	return 0;
}

static int test_assertions2()
{
	YLATEST_ASSERT_TRUE(1, "true assertion incorrect");

// uncomment this to check if test suite work correctly (failing) with failed test case
//	YLATEST_ASSERT_FALSE(1, "false assertion incorrect");

	return 0;
}

YLATEST_BEGIN(yla_test_test)
  YLATEST_ADD_TEST_CASE(test_assertions)
  YLATEST_ADD_TEST_CASE(test_assertions2)
YLATEST_END
