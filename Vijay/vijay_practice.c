#include <stdio.h>

int list[10] = {2,3,4,5,6,1,19,25,4,15};
int max_value(int);
int sum(int, int);

int a,b;

int hello_v() {

	int result,result1;

   printf("Welcome Team6.!");

   result = max_value(list[10]);
   result1 = sum(a,b);

   printf("The results are %d,%d",result,result1);

   return 0;
}

/* function to find the maximum value from a list of number*/
int max_value(list[10])
{

int max_value = 0;

for(int j=0;j<10;j++)
{
	if(max_value < list[j])
	{
		max_value = list[j];
	}
}

printf("The Maximum value in the list is %d",max_value);

return max_value;

}

int sum(a,b)
{
	return a+b;
}
