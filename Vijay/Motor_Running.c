#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Motor_Running.h"

#define SIZE 10

typedef struct {
   int current;
   int voltage;
   int speed;
   int key;
}DataItem;

DataItem* hashArray[SIZE];
DataItem* dummyItem;
DataItem* item;

int Run_motor(int);

void display_value();

int hashCode(int);

int rpm ,speed1 = 0,speed2 = 0;
extern select;

int Run_motor(int value)
{
	select = value;

//	   dummyItem = (DataItem*) malloc(sizeof(DataItem));
	   dummyItem->current = 0;
	   dummyItem->voltage = 0;
	   dummyItem->speed = 0;
	   dummyItem->key = -1;

	switch(select)
	{
	case 0:

		for(int i=0;i<=1000;i+100)
		{
//			   DataItem *item = (DataItem*) malloc(sizeof(DataItem));
			   item->current = 10;
			   item->voltage = 230;
			   item->key = item->key + 1;

			   int hashIndex = hashCode(item->key);

			if(hashArray[hashIndex]->current  >0 && hashArray[hashIndex]->voltage > 0)
			{
				hashArray[hashIndex]->speed = hashArray[hashIndex]->speed + 100;
			}
		}
		//display_value();
		rpm = hashArray[SIZE]->speed;
		break;

	case 1:

		for(int i=0;i<=1000;i+100)
		{
			   DataItem *item = (DataItem*) malloc(sizeof(DataItem));
			   item->current = 10;
			   item->voltage = 230;
			   item->key = item->key + 1;

			   int hashIndex = hashCode(item->key);

			if(hashArray[hashIndex]->current  >0 && hashArray[hashIndex]->voltage > 0)
			{
				hashArray[hashIndex]->speed = hashArray[hashIndex]->speed + 100;
			}
		}
		//display_value();

		rpm = hashArray[SIZE]->speed;

		break;

	default:
		break;
	}
	return rpm;
}

int hashCode(int key)
{
   return key % SIZE;
}

//void display_value() {
//   int i = 0;
//
//   for(i = 0; i<SIZE; i++) {
//
//      if(hashArray[i] != NULL)
//         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->speed);
//      else
//         printf(" ~~ ");
//   }
//
//   printf("\n");
//}

