#ifndef HELLO_H

#define HELLO_H



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




// define functions here
int hello_c();
int hello_e();
int hello_g();
int hello_v();
int hello_d();

int add(int a, int b);
float temp_sensor_converter(int temp_sensor_value, bool* success);
float temp_c_to_f(float temp_c);
bool readings_to_temp_c_and_f_arrays(int *temp_sesnor_readings_ptr, float *temp_c_arr_ptr, float *temp_f__arr_ptr, int number_readings);

/*Deepa*/
int func_add(int p, int q);
int func_sub(int p, int q);
int func_multi(int p, int q);
int math_op(int a, int b);
int add_array(int* a, int num_elements);
int array_addition(); 
int func_malloc();
int func_date();
int seq_sum();

#endif
