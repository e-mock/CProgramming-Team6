#include <stdio.h>
#include <stdlib.h>

int a, b, p, q, n;

int hello_d()
{
    printf("New World");
}

int math_op(a,b) {

    /* Local variables to hold results*/
    int tst_add;
    int tst_sub;
    int tst_multi;

    printf("Simple Mathematics Calculations\n");
    tst_add = func_add(a, b);
    tst_sub = func_sub(a, b);
    tst_multi = func_multi(a, b);

    return 0;
}


/* Functions declaration*/

/*Addition function*/
int func_add(p, q)
{
    int add_val, *add_ptr;
    add_ptr = &add_val;
    add_val = (p + q);
    printf("Sum : %d\n", add_val);
    printf("Address of Sum variable : %p\n", add_ptr);
    return add_val;
}

/*Subtract function : Max value - Min Value*/
int func_sub(p, q)
{
    int sub_val, *sub_ptr;
    sub_ptr = &sub_val;
    if (p > q)
        sub_val = p - q;
    else
        sub_val = q - p;
    printf("Difference : %d\n", sub_val);
    printf("Address of Diff variable : %p\n", sub_ptr);
    return sub_val;
}

/*Multiplication function*/
int func_multi(p, q)
{
    int mul_val, *mul_ptr;
    mul_ptr = &mul_val;
    mul_val = (p * q);
    printf("Multiplied Value : %d\n", mul_val);
    printf("Address of Multiplied variable : %p\n", mul_ptr);
    return mul_val;
}

/*Addition of array members*/
int add_array(int* p, int size) {
    int total = 0;
    int k;
    for (k = 0; k < size; k++) {
        total += p[k];  /* it is equivalent to total +=*p ;p++; */
    }
    return (total);
}

/*Dynamic Memory allocation*/

/*malloc()*/
int func_malloc()
{
    int i, *ptr, sum = 0;
    int arr[10];
    
    n = 5;
    ptr = (int*) malloc(n * sizeof(int));
    
    for(i = 0; i < n; ++i)
    {
        *(p+i) = i+10;
        printf("Array Values : %d\n", p+i);
    }
    
    // if memory cannot be allocated
    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    
    for(i = 0; i < n; ++i)
    {
         sum += *(p+i);
    }
    
    printf("\nSum = %d\n", sum);
  
    // deallocating the memory
    free(ptr);

    return 0;
}
