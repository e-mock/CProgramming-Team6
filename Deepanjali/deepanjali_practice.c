#include <stdio.h>

int a, b, p, q;

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
