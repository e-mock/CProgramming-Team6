#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "hello.h"

void test_sum(void)
{
    CU_ASSERT(sum(2,2) == 4);
    CU_ASSERT(sum(0, 0) == 0);
    CU_ASSERT(sum(-1, 1) == 0);
}

int main() {

    CU_initialize_registry();

    CU_pSuite suite1 = CU_add_suite("test_sum", 0, 0);

    CU_add_test(suite1, "test_sum", test_sum);

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    CU_cleanup_registry();


    return 0;

}
