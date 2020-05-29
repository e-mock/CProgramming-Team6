#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct thread_data {
	int thread_id;	
	int num_elem;
	int result;
	int a[10];
} thread_data;

void *myThreadFun(void *vargp) 
{     
    thread_data *tdata = (thread_data *) vargp;
    int id = tdata->thread_id;
    int* arr = tdata->a;
    
    int arr_size = tdata->num_elem;
    int sum = 0;
    
    printf("Running thread %d\n", id);
    
    for(int i = 0; i < arr_size; i++){
    	sum += arr[i];
    	printf("%d + ", arr[i]);
    }
    
    tdata->result = sum;
    
    
    //fflush(stdout);
    //sleep(1); 
    printf("Thread %d: partial sum is %d \n", id, sum); 
    //fflush(stdout);
    
    long status = 10;
    pthread_exit((void*) status);
} 

void gen_rand_int_array(int* arr, int arr_size, int rand_max){
	int num;
	printf("Generating random array with %d elements and max element of %d\n", arr_size, rand_max);
	for(int i = 0; i < arr_size; i++){
		
		num = rand() % rand_max;
		printf("%d ", num);
		arr[i] = num;
	}
	printf("\n\n");
}
   
int main() 
{ 
    
    int arr_size = 100;
    
    int arr[arr_size];//{0, 1, 2, 3, 4, 10};
    
    
    thread_data tdata;    
    int i = 0;
    //int arr_size = sizeof(arr)/sizeof(int);
    int num_threads = 10;
    int j = 0;
        
    pthread_t threads[arr_size];
    thread_data thread_data_arr[arr_size];
        
    int arr_elems_per_thread = arr_size/num_threads;
    
    gen_rand_int_array(arr, arr_size, 1000);
    
    printf("Generated random array: \n");
    for(i = 0; i < arr_size; i++){
    	printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    
    
    for(i = 0; i < num_threads; i++){

    	   	printf("Making struct for %d\n", i);
    	thread_data tdata2;
    	tdata2.thread_id = i;
    	tdata2.num_elem = arr_elems_per_thread;
    	
    	//int a[arr_elems_per_thread];  	
    	
    	for(j = 0; j < arr_elems_per_thread; j++){
    		tdata2.a[j] = arr[arr_elems_per_thread * i + j];
    		printf("%d ", arr[arr_elems_per_thread * i + j]);
    	}
    	
    	
    	
 
    	//tdata2.a = a;
    	printf("\n checking split array \n");
    	for(j = 0; j < arr_elems_per_thread; j++){
    	     printf("%d ", tdata2.a[j]);
    	} 
    	    	
    	//tdata2.a = a;
    	
    	//(thread_data)* temp = realloc(thread_data_arr[i], sizeof(tdata2));
    	//thread_data_arr[i] = temp;
    	thread_data_arr[i] = tdata2;
    	
    	printf("\n\n");
    }
    
    
    for(i = 0; i < num_threads; i++){
    	tdata = thread_data_arr[i];
    	printf("Thread struct %d\n", tdata.thread_id);
    	int* thread_arr = tdata.a;
    	
    	for(j = 0; j < arr_elems_per_thread; j++){
    	     printf("%d ", thread_arr[j]);
    	} 
    	
    	printf("\n\n");
    }
    
    printf("Before Thread\n"); 
    
    for(i = 0; i < num_threads; i++){
    	pthread_create(&threads[i], NULL, myThreadFun, (void*)(&(thread_data_arr[i]))); 
    }
    
    void* status;

    
    printf("Joining threads\n");
    
    int sum = 0;
    int partial_sum = 0;
    
    for(i = 0; i < num_threads; i++)
    {
    	int t = pthread_join(threads[i], &status);
    	if(t != 0){
    	     printf("Error in thread join: %d\n", t);
    	} 
    	else{
    	     tdata= thread_data_arr[i];
    	     partial_sum = tdata.result;
    	     printf("Thread %d calculated partial sum %d\n", tdata.thread_id, partial_sum);
    	     sum += partial_sum;
    	
	}
    }
    
    printf("all the elements added is %d\n", sum);
    
      
    
    printf("After Thread\n"); 
    
    printf("freeing allocated memory\n");
    for(i = 0; i < num_threads; i++){
    	tdata = thread_data_arr[i];
    	//free(tdata.a);
    }
    
    
    exit(0); 
}
