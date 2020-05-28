#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "hello.h"

void basic_math(void)
{
    CU_ASSERT(func_add(2,2) == 4);
    CU_ASSERT(func_sub(10, 20) == 10);
    CU_ASSERT(func_multi(54, 30) == 1620);
}

int array_addition() {
    int Tab[5] = { 100, 220, 37, 16, 98 };
    printf("\nTotal summation is %d\n", add_array(Tab, 5));
    return 0;
}

int main() {

    CU_initialize_registry();

    CU_pSuite suite1 = CU_add_suite("basic_math", 0, 0);
    CU_pSuite suite2 = CU_add_suite("array_addition", 0, 0);
    CU_pSuite suite3 = CU_add_suite("func_date", 0, 0);
    CU_pSuite suite4 = CU_add_suite("seq_sum", 0, 0);

    CU_add_test(suite1, "basic_math", basic_math);
    CU_add_test(suite2, "array_addition", array_addition);
    CU_add_test(suite3, "func_date", func_date);
    CU_add_test(suite3, "seq_sum", seq_sum);

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    CU_cleanup_registry();


    return 0;

}
