#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "hello.h"

void basic_math(void)
{
    CU_ASSERT(func_add(2,2) == 4);
    CU_ASSERT(func_sub(10, 20) == 10);
    CU_ASSERT(func_multi(54, 30) == 1620);
}

int Cunit_main() {

    CU_initialize_registry();

    CU_pSuite suite1 = CU_add_suite("basic_math", 0, 0);

    CU_add_test(suite1, "basic_math", basic_math);

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    CU_cleanup_registry();


    return 0;

}
