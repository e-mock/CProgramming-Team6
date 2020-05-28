#include <stdio.h>

float p,q;
float a,b;
void hello_d() {

 /* Local variables to hold results*/
    int tst_add;
    int tst_sub;
    int tst_multi;
    float tst_div;

    tst_add = func_add(a, b);
    tst_sub = func_sub(a, b);
    tst_multi = func_multi(a, b);
    tst_div = func_div(a, b);

    printf("Basic mathematics operation Results\n");
    printf("Addition : %d\n", tst_add);
    printf("Subtraction : %d\n", tst_sub);
    printf("Multiplication : %d\n", tst_multi);
    printf("Division : %f\n", tst_div);

   return 0;
}


/* Functions declaration*/

/*Addition function*/
int func_add(p,q)
{
    return (p + q);
}

/*Subtract function : Max value - Min Value*/
int func_sub(p, q)
{
    int x;
    if (p > q)
        x = p - q;
    else
        x = q - p;
    return x;
}

/*Multiplication function*/
int func_multi(p, q)
{
    return (p * q);
}

/*Division function*/
void func_div(p, q)
{
    float y;
    y = (p / q);
    return y;

}
