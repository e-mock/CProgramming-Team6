
// #include <CUnit/CUnit.h>
// #include <CUnit/Headers/Basic.h>
#include "hello.h"

// int maxi(int i1, int i2)

// {

//     return (i1 > i2) ? i1 : i2;

// }



// void test_maxi(void)

// {

//     CU_ASSERT(maxi(0,2) == 2);

// }

void test_add(void)
{
    CU_ASSERT(sum(2,2) == 4);
    CU_ASSERT(sum(0, 0) == 0);
    CU_ASSERT(sum(-1, 1) == 0);
}

void test_temp_sensor_to_c(void){
    bool success = false;
    
    CU_ASSERT(temp_sensor_converter(0, &success), -55.0);
    CU_ASSERT(temp_sensor_converter(0, &success), -55);
    CU_ASSERT(temp_sensor_converter(1023, &success), 125.0);
    
}

int main() {

    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("test_add", 0, 0);



    CU_add_test(suite, "test_add", test_add);



    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    CU_cleanup_registry();



    return 0;

}