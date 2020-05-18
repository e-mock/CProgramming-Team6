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

float temp_sensor_converter(int temp_sensor_value, bool* success);
float temp_c_to_f(float temp_c);
int add(int a, int b);

#endif