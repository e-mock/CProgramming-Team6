#include <stdio.h>
#include <stdbool.h>

const float TEMP_C_MIN = -55.0;
const float TEMP_C_MAX = 125.0;
const int TEMP_SENSE_MIN = 0;
const int TEMP_SENSE_MAX = 1023;
const float TEMP_C_IF_INVALID = -100.0;
const float TEMP_F_IF_INVALID = -200.0;

// adds 2 ints, stub for testing
int add(int a, int b)
{
   int sum = a + b;
   return sum;
}

// Takes temp_sensor_value that is an int between 0 and 1023 and converts it to a float temp_celsius between -55 and 125
float temp_sensor_converter(int temp_sensor_value, bool *success)
{
   float temp_celsius = 0;
   // 0 reading = -55 C temp, 1023 reading = 125 C temp, assuming linear relationship

   if (temp_sensor_value < TEMP_SENSE_MIN || temp_sensor_value > TEMP_SENSE_MAX)
   {
      //change success to false
      printf("Temperature sensor value (%d) is not in the range of %d to %d, changing success to false.\n", temp_sensor_value, TEMP_SENSE_MIN, TEMP_SENSE_MAX);
      *success = false;
      return -100;
   }

   printf("Temperature sensor value (%d) is in the range of %d to %d\n Attempting conversion now ...\n", temp_sensor_value, TEMP_SENSE_MIN, TEMP_SENSE_MAX);

   //slope of a line with endpoints (TEMP_SENSE_MIN, TEMP_C_MIN) and (TEMP_SENSE_MAX, TEMP_C_MAX) where temp_sense is on the x axis and temp_c is on the y axis
   float TEMP_SLOPE = (TEMP_C_MAX - TEMP_C_MIN) / (1.0 * (TEMP_SENSE_MAX - TEMP_SENSE_MIN));

   //y = mx+b, y is the temp_c, m is TEMP_SLOPE, x is the temp_sense, and b is TEMP_C_Min
   temp_celsius = TEMP_SLOPE * temp_sensor_value + TEMP_C_MIN;

   if (temp_celsius < TEMP_C_MIN || temp_celsius > TEMP_C_MAX)
   {
      //change success to false
      printf("Temperature celsius value (%f) is not in the range of %f to %f, changing success to false.\n", temp_celsius, TEMP_C_MIN, TEMP_C_MAX);
      *success = false;
      return -200;
   }

   printf("Temperature sensor value (%d) was converted successfully to temperature %f C in the range of %f C to %f C.\n", temp_sensor_value, temp_celsius, TEMP_C_MIN, TEMP_C_MAX);

   *success = true;
   return temp_celsius;
}

// Converts temperature from Celsius to Fahrenheit
float temp_c_to_f(float* temp_c)
{
   float temp_f = (9.0 / 5.0) * *temp_c + 32.0;
   printf("Temperature %f C = %f F\n", *temp_c, temp_f);
   return temp_f;
}

// Need to declare and initialize an array with temp sensor readings and declare 2 float arrays of the same size and pass them to this function to convert the reading to temp C and temp F and populate the arrays
// pointer to array idea from https://www.tutorialspoint.com/cprogramming/c_pointer_to_an_array.htm after trying a lot of other ways
bool readings_to_temp_c_and_f_arrays(int *temp_sesnor_readings_ptr, float *temp_c_arr_ptr, float *temp_f__arr_ptr, int number_readings)
{
   int i = 0;

   bool success = true;
   bool temp_success = false;

   float temp_c;
   float temp_f;
   //https://www.ibm.com/support/knowledgecenter/SSLTBW_2.4.0/com.ibm.zos.v2r4.cbclx01/cplr242.htm
   //https://www.geeksforgeeks.org/function-pointer-in-c/
   //https://cs.nyu.edu/courses/spring12/CSCI-GA.3033-014/Assignment1/function_pointers.html
   // pointer to temp_c_to_f that uses pointer
   float (*fun_ptr)(float*);
   fun_ptr = temp_c_to_f;

   for (i = 0; i < number_readings; i++)
   {
      int temp_sensor_reading = *(temp_sesnor_readings_ptr + i);

      printf("Processing temp sensor reading: %d . . .\n", temp_sensor_reading);

      temp_c = temp_sensor_converter(temp_sensor_reading, &temp_success);

      if (temp_success)
      {
         // temp_f = temp_c_to_f(&temp_c);
         temp_f = (*fun_ptr)(&temp_c);
         printf("Temp Sensor reading: %d, temperature(C): %f, temperature(F): %f \n", temp_sensor_reading, temp_c, temp_f);

         *(temp_c_arr_ptr + i) = temp_c;
         *(temp_f__arr_ptr + i) = temp_f;
      }
      else
      {
         printf("Error converting temperature sensor reading (%d) to degrees Celsius, skipped converting to degrees Fahrenheit\n", temp_sensor_reading);
         *(temp_c_arr_ptr + i) = TEMP_C_IF_INVALID;
         *(temp_f__arr_ptr + i) = TEMP_F_IF_INVALID;
      }

      success &= temp_success;
   }

   printf("Done creating arrays, testing printing arr in function\n");

   for (i = 0; i < number_readings; i++)
   {
      printf("i: %d, reading: %d, tempc: %f, tempf %f\n", i, *(temp_sesnor_readings_ptr + i), *(temp_c_arr_ptr + i), *(temp_f__arr_ptr + i));
   }

   return success;
}

int hello_e()
{
   // Calls the functions in elizabeth_practice.c for seeing how they run in a limited way
   printf("Hello E.!\n");

   // int temp_sensor_readings[] = {0, 100, 1023};
   
   //pretend this was read by scanf
   int desired_n = 3;

   int i = 0;

   int* temp_sensor_readings = (int*)malloc(desired_n * sizeof(int));
   
   int number_readings = sizeof(temp_sensor_readings) / sizeof(int);

   print("There are %d spots for sensor readings.", number_readings);
   
   for(i = 0; i < number_readings; i++){
      printf("Index %d has value %d\n", i, temp_sensor_readings[i]);
   }

   printf("setting values\n");
   for(i = 0; i < number_readings; i++){
      temp_sensor_readings[i] = 511*i;
   }

   printf("Done setting values\n");
   for(i = 0; i < number_readings; i++){
      printf("Index %d has value %d\n", i, temp_sensor_readings[i]);
   }



   bool success = false;

   float temp_c;
   float temp_f;

   float temp_c_arr[number_readings];
   float temp_f_arr[number_readings];
   
   success = readings_to_temp_c_and_f_arrays(temp_sensor_readings, temp_c_arr, temp_f_arr, number_readings);

   if (success)
   {
      printf("Done creating arrays, testing printing arr outside function\n");
   }
   else
   {
      printf("Invalid value in temp_sensor_readings, temp_c = %f and temp_f = %f for those values\n", TEMP_C_IF_INVALID, TEMP_F_IF_INVALID);
   }

   for (i = 0; i < number_readings; i++)
   {
      printf("i: %d, reading: %d, tempc: %f, tempf %f\n", i, temp_sensor_readings[i], temp_c_arr[i], temp_f_arr[i]);
   }
   // for(i = 0; i < number_readings; i++){
   //    int temp_sensor_reading = temp_sensor_readings[i];
   //    temp_c = temp_sensor_converter(temp_sensor_reading, &success);

   //    if(success) {
   //    temp_f = temp_c_to_f(temp_c);
   //    printf("Temp Sensor reading: %d, temperature(C): %f, temperature(F): %f \n", temp_sensor_reading, temp_c, temp_f);
   //    }
   //    else {
   //       printf("Error converting temperature sensor reading (%d) to degrees Celsius, skipped converting to degrees Fahrenheit\n", temp_sensor_reading);
   //    }
   // }

   free(temp_sensor_readings);

   return 0;
}