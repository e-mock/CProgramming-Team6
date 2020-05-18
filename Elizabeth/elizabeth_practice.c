#include <stdio.h>
#include <stdbool.h>

const float TEMP_C_MIN = -55.0;
const float TEMP_C_MAX = 125.0;
const int TEMP_SENSE_MIN = 0;
const int TEMP_SENSE_MAX = 1023;

int add(int a, int b){
   int sum = a + b;
   return sum;
}

void sortAscending(int* arr, int size){
   int i = 0;

   for(i = 0; i < size; i++){
      printf("%d ", arr[i]);
   }
}

// void getIntInputArray(int* arr, int max_size){
//    printf("Enter an integer (-1 to quit)\n");
//    int num = 0;
//    // int max_size = sizeof(arr)/sizeof(int);
//    int size = 0;
//    int i = 0;

//    printf("The array was allocated space for %d ints", max_size);

//    while(num != -1 && size < max_size){
//       printf("Enter an integer (-1 to quit)\n");
//       scanf("%d", &num);

//       printf("Received int: %d\n", num);
//       arr[size] = num;
//       size++;
//    }

//    for(i = size; i < max_size; i++){
//       arr[i] = 0;
//    }

//    if(size == max_size){
//       printf("Array is full\n");
//    }

//    if(size > max_size){
//       printf("Array overflowed !!!\n");
//    }

//    printf("The array has values: ");
//    for(i = 0; i<max_size; i++){
//       printf("%d ", arr[i]);
//    }

//    printf("\n");
   
   
// }

// takes temp_sensor_value that is an int between 0 and 1023 and converts it to a float temp_celsius between -55 and 125
float temp_sensor_converter(int temp_sensor_value, bool* success){
   float temp_celsius = 0;
   // 0 reading = -55 C temp, 1023 reading = 125 C temp, assuming linear relationship

   if(temp_sensor_value < TEMP_SENSE_MIN || temp_sensor_value > TEMP_SENSE_MAX){
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

   if(temp_celsius < TEMP_C_MIN || temp_celsius > TEMP_C_MAX){
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
float temp_c_to_f(float temp_c){
   float temp_f = (9.0/5.0) * temp_c + 32.0;
   printf("Temperature %f C = %f F\n", temp_c, temp_f);
   return temp_f;
}

int hello_e() {
   printf("Hello E.!\n");

   int temp_sensor_readings[] = {0, 100, 1023, -1, 1024};
   int number_readings = sizeof(temp_sensor_readings) / sizeof(int);
   // getIntInputArray(temp_sensor_readings, number_readings);

   
   int i = 0;

   bool success = false;
   float temp_c;
   float temp_f;

   for(i = 0; i < number_readings; i++){
      int temp_sensor_reading = temp_sensor_readings[i];
      temp_c = temp_sensor_converter(temp_sensor_reading, &success);

      if(success) {
      temp_f = temp_c_to_f(temp_c);
      printf("Temp Sensor reading: %d, temperature(C): %f, temperature(F): %f \n", temp_sensor_reading, temp_c, temp_f);
      }
      else {
         printf("Error converting temperature sensor reading (%d) to degrees Celsius, skipped converting to degrees Fahrenheit\n", temp_sensor_reading);
      }
   }


   
   
   return 0;
}
