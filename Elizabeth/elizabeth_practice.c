#include <stdio.h>
#include <stdbool.h>

const float TEMP_C_MIN = -55.0;
const float TEMP_C_MAX = 125.0;
const int TEMP_SENSE_MIN = 0;
const int TEMP_SENSE_MAX = 1023;

//slope of a line with endpoints (TEMP_SENSE_MIN, TEMP_C_MIN) and (TEMP_SENSE_MAX, TEMP_C_MAX) where temp_sense is on the x axis and temp_c is on the y axis
const int TEMP_SLOPE = (TEMP_C_MAX - TEMP_C_MIN) / (1.0 * (TEMP_SENSE_MAX - TEMP_SENSE_MIN));

int add(int a, int b){
   int sum = a + b;
   return sum;
}

int hello_e() {
   printf("Hello E.!");
   
   return 0;
}

// takes temp_sensor_value that is an int between 0 and 1023 and converts it to a float temp_celsius between -55 and 125
float temp_sensor_converter(int temp_sensor_value, bool* success){
   float temp_celsius = 0;
   // 0 reading = -55 C temp, 1023 reading = 125 C temp, assuming linear relationship

   if(temp_sensor_value < TEMP_SENSE_MIN || temp_sensor_value > TEMP_SENSE_MAX){
      //change success to false
      printf("Temperature sensor value (%d) is not in the range of %d to %d, changing success to false.\n", temp_sensor_value, TEMP_SENSE_MIN, TEMP_SENSE_MAX);
      *success = false;
      return -1;
   }

   printf("Temperature sensor value (%d) is in the range of %d to %d\n Attempting conversion now ...\n", temp_sensor_value, TEMP_SENSE_MIN, TEMP_SENSE_MAX);
      

   //y = mx+b, y is the temp_c, m is TEMP_SLOPE, x is the temp_sense, and b is TEMP_C_Min
   temp_celsius = TEMP_SLOPE * temp_sensor_value + TEMP_C_MIN;

   if(temp_celsius < TEMP_C_MIN || temp_celsius > TEMP_C_MAX){
      //change success to false
      printf("Temperature celsius value (%f) is not in the range of %f to %f, changing success to false.\n", temp_celsius, TEMP_C_MIN, TEMP_C_MAX);
      *success = false;
      return -2;
   }

   printf("Temperature sensor value (%d) was converted successfully to temperature %f C in the range of %f C to %f C.\n", temp_sensor_value, temp_celsius, TEMP_C_MIN, TEMP_C_MAX);
      
   *success = true;
   return temp_celsius;
}