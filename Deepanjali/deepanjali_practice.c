#include <stdio.h>

int p,q;
int hello_d() {

 /* Local variables to hold results*/
    int tst_add;
    int tst_sub;
    int tst_multi;
    float tst_div;
    int a = 10, b = 20;

    tst_add = func_add(a, b);
    tst_sub = func_sub(a, b);
    tst_multi = func_multi(a, b);
    tst_div = func_div(a, b);

    printf("Basic mathematics operation Results");
    printf("Addition : %d", tst_add);
    printf("Subtraction : %d", tst_sub);
    printf("Multiplication : %d", tst_multi);
    printf("Division : %f", tst_div);

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
