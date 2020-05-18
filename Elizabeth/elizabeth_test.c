#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
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
    CU_ASSERT(add(2,2) == 4);
    CU_ASSERT(add(0, 0) == 0);
    CU_ASSERT(add(-1, 1) == 0);
}

void test_temp_c_to_f(void){
    //                     temp C     tempF
    CU_ASSERT(temp_c_to_f(-40.0) == -40.0);
    CU_ASSERT(temp_c_to_f(0.0) == 32.0);    
    CU_ASSERT(temp_c_to_f(25.0) == 77.0);
    CU_ASSERT(temp_c_to_f(100.0) == 212.0);
}

void test_temp_sensor_to_c_valid(void){
    bool success = false;
    float temp_c = -300.0;

    int inputs[] = {0, 511, 1023};
    float expected_outputs[] = {-55.0, 34.9, 125.0};

    float tolerance = 0.1;

    //num_tests has number of elements in inputs array
    int num_tests = sizeof(inputs)/sizeof(inputs[0]); 

    int i = 0;

    for(i = 0; i < num_tests; i++){
        CU_ASSERT(temp_sensor_converter(inputs[i], &success) >= expected_outputs[i] - tolerance);
        CU_ASSERT(success == true); 

        CU_ASSERT(temp_sensor_converter(inputs[i], &success) <= expected_outputs[i] + tolerance);
        CU_ASSERT(success == true); 
    }
    // // expect -55.0
    // CU_ASSERT(temp_sensor_converter(0, &success) >= -54.0);
    // CU_ASSERT(success == true);    
    
    // // expect 34.912
    // CU_ASSERT(temp_sensor_converter(511, &success) >= 34.912);
    // CU_ASSERT(success == true);
    
    // // expect 125.0
    // CU_ASSERT(temp_sensor_converter(1023, &success) == 125.0);
    // CU_ASSERT(success == true);
    
}

void test_temp_sensor_to_c_invalid(void){
    bool success = true;
    
    CU_ASSERT(temp_sensor_converter(-100, &success) == -100.0);
    CU_ASSERT(success == false); 
    
    CU_ASSERT(temp_sensor_converter(-1, &success) == -100.0);
    CU_ASSERT(success == false);    
    
    CU_ASSERT(temp_sensor_converter(1024, &success) == -100.0);
    CU_ASSERT(success == false);
    
    CU_ASSERT(temp_sensor_converter(1100, &success) == -100.0);
    CU_ASSERT(success == false);   
    
}

int main() {

    CU_initialize_registry();

    CU_pSuite suite1 = CU_add_suite("test_add", 0, 0);
    CU_pSuite suite2 = CU_add_suite("test_temp_c_to_f", 0, 0);
    CU_pSuite suite3 = CU_add_suite("test_temp_sensor_to_c_valid", 0, 0);
    CU_pSuite suite4 = CU_add_suite("test_temp_sensor_to_c_invalid", 0, 0);



    CU_add_test(suite1, "test_add", test_add);
    CU_add_test(suite2, "test_temp_c_to_f", test_temp_c_to_f);
    CU_add_test(suite3, "test_temp_sensor_to_c_valid", test_temp_sensor_to_c_valid);
    CU_add_test(suite4, "test_temp_sensor_to_c_invalid", test_temp_sensor_to_c_invalid);
    


    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    CU_cleanup_registry();



    return 0;

}
