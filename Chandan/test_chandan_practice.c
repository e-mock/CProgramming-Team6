#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "hello.h"
void test_sum(void)
{
    CU_ASSERT(addn(14.5,16,17.5) == 48);
    CU_ASSERT(addn(0, 0, 0) == 0);
    CU_ASSERT(addn(-1, 1, 30) == 30);
    CU_ASSERT(addn(-1.8,2,1.8) == 2);
}
int main() {
    CU_initialize_registry();
    CU_pSuite suite1 = CU_add_suite("test_addition", 0, 0);
    CU_add_test(suite1, "test_addition", test_addition);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
