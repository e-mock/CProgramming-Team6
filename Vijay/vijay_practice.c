#include <stdio.h>
#include "Motor_Running.h"

int list[10] = {2,3,4,5,6,1,19,25,4,15};/* list to find max value*/
int max_value();
int sum(int, int);
extern int Run_motor(int);

int a,b;

int select = M1;

int hello_v() {

	int result,result1;

   printf("Welcome Team6.!");

   result = max_value();
   result1 = sum(a,b);

   Run_motor(select);

   printf("The results are %d,%d",result,result1);

   return 0;
}


/* function to find the maximum value from a list of number*/
int max_value()
{

int max_value = 0;

int j;
for(j=0;j<10;j++)
{
	if(max_value < list[j])
	{
		max_value = list[j];
	}
}

printf("The Maximum value in the list is :%d",max_value);

return max_value;

}

int sum(int a,int b)
{
	return a+b;
}



