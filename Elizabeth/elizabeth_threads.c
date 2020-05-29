#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//based on https://www.geeksforgeeks.org/multithreading-c-2/

typedef struct thread_data {
	int thread_id;
	int a;
	int result;
} thread_data;

void *myThreadFun(void *vargp) 
{     
    thread_data *tdata = (thread_data *) vargp;
    int id = tdata->thread_id;
    int arr_val = tdata->a;
    
    int doubled = 2 * arr_val;
    
    tdata->result = doubled;
    
    //printf("Running thread %d\n", id);
    //fflush(stdout);
    //sleep(1); 
    printf("Thread %d: %d doubled is %d \n", id, arr_val, doubled); 
    //fflush(stdout);
    
    long status = 10;
    pthread_exit((void*) status);
} 
   
int main() 
{ 
    int arr[] = {0, 1, 2, 3, 4, 10};
    thread_data tdata;    
    int i = 0;
    int arr_size = sizeof(arr)/sizeof(int);
    pthread_t threads[arr_size];
    thread_data thread_data_arr[arr_size];
    
    for(i = 0; i < arr_size; i++){
    	tdata = thread_data_arr[i];
    	tdata.thread_id = i;
    	tdata.a = arr[i];
    	thread_data_arr[i] = tdata;
    }
    
    printf("Before Thread\n"); 
    
    for(i = 0; i < arr_size; i++){
    	pthread_create(&threads[i], NULL, myThreadFun, (void*)&(thread_data_arr[i])); 
    }
    
    void* status;
    for(i = 0; i < arr_size; i++){
    	tdata = thread_data_arr[i];
    	printf("Thread data: a: %d, result: %d\n", tdata.a, tdata.result);
    }
    
    printf("Joining threads\n");
    
    for(i = 0; i < arr_size; i++)
    {
    	int t = pthread_join(threads[i], &status);
    	if(t != 0){
    	     printf("Error in thread join: %d\n", t);
    	} 
    }
    
    for(i = 0; i < arr_size; i++){
    	tdata = thread_data_arr[i];
    	printf("Thread data: a: %d, result: %d\n", tdata.a, tdata.result);
    }
    
    
    
    printf("After Thread\n"); 
    exit(0); 
}
