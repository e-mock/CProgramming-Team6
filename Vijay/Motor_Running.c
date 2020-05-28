#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include "Motor_Running.h"
//
#define SIZE 10

typedef struct {
   int current;
   int voltage;
   int speed;
   int key;
}DataItem;

DataItem* hashArray[SIZE];
DataItem* item;

int Run_motor(int);

void display_value();

int hashCode(int);

int rpm ,speed1 = 0,speed2 = 0;

int Run_motor(int value)
{
	switch(value)
	{
	case 0:

		for(int i=0;i<SIZE;i++)
		{
			item = (DataItem*) malloc(sizeof(DataItem));
			item->current = 10;
			item->voltage = 230;
			item->key = i;

			   int hashIndex = hashCode(item->key);

			if(item->current  >0 && item->voltage > 0)
			{
				item->speed = item->speed + 100;
			}

			hashArray[hashIndex] = item;

		}
		display_value();
		rpm = hashArray[SIZE]->speed;
		break;
	case 1:

		for(int i=0;i<SIZE;i++)
		{
			item = (DataItem*) malloc(sizeof(DataItem));
			item->current = 10;
			item->voltage = 230;
			item->key = i;

			   int hashIndex = hashCode(item->key);

			if(item->current  >0 && item->voltage > 0)
			{
				item->speed = item->speed + 100;
			}

			hashArray[hashIndex] = item;

		}
		display_value();
		rpm = hashArray[SIZE]->speed;
		break;

	default:
		break;
	}
	return 0;
}

int hashCode(int key)
{
   return key % SIZE;
}

void display_value() {
   int i = 0;

   for(i = 0; i<SIZE; i++) {

      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->speed);
      else
         printf(" ~~ ");
   }

   printf("\n");
}

