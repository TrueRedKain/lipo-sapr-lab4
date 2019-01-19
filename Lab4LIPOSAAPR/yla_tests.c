#include "yla_test.h"

YLATEST_SUITE_BEGIN(yla_suite)
  YLATEST_ADD_TEST(yla_test_test)
  YLATEST_ADD_TEST(yla_stack_test)
  YLATEST_ADD_TEST(yla_vm_test1)
YLATEST_SUITE_END


int main()
{
	return yla_suite();
}
