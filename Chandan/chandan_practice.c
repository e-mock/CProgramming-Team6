#include<stdio.h>
#include<math.h>
int hello_c()
{
   float a = 14.5;
   float b = 16;
   float c = 17.5;
   int x = 3;
   int y = 6;
   int z = 5;
   int i, HCF, max, step, LCM;
   float sum, prod, divs, mod, modu, cira, cirb;
   float sub, diff, divi, s, area, cir, rec;
   printf("\n The values are A = %f, B = %f, C=%f \n", a,b,c );
   printf(" \n The values of X = %d, Y = %d, Z= %d \n", x,y,z);

   printf("\n The sum of all the numbers");
   sum = a + b + c;
   printf(" \n sum = %f \n", sum);

   printf("\n The difference of B and A ");
   sub = b - a;
   printf("\n difference = %f", sub);

   printf("\n The difference of C and B");
   diff = c - b;
   printf("\n difference = %f \n ", diff);

   printf(" \n The product of all numbers ");
   prod = a * b * c;
   printf("\n the product = %f \n", prod);

   printf("\n The division of B and A ");
   divs = b/a;
   printf(" \n The quotient = %f  \n", divs);

   printf("\n The division of C and B ");
   divi = c/b;
   printf("\n The quotient = %f \n", divi);

   printf(" \n The even and Odd numbers of X, Y and Z :");
   if( x%2 == 0)
   printf ("\n X is an even number which is: %d ", x);
   else
   printf("\n X is an odd number which is : %d ", x);

   if( y%2 == 0)
   printf ("\n Y is an even number which is: %d", y);
   else
   printf("\n Y is an odd number which is : %d", y);

   if( z%2 == 0)
   printf ("\n Z is an even number which is: %d",z);
   else
   printf("\n Z is an odd number which is : %d \n", z);


   printf(" \n The greatest of A, B and C");
   if(a>b && a>c)
   printf(" \n A is greater which is %f \n", a);
   else if( b>a && b>c)
   printf(" \n B is greater which is %f \n", b);
   else
   printf("\n C is greater which is %f \n", c);

   printf(" \n The greatest of X, Y and Z");
   if(x>y && x>z)
   printf(" \n X is greater which is %d \n", x);
   else if( y>x && y>z)
   printf(" \n Y is greater which is %d \n", y);
   else
   printf("\n Z is greater which is %d \n", z);

   printf("\n The area of triangle A, B and C");
   s= (sum)/ 2;
   area = sqrt(s * (s - a) * (s - b) * (s - c));
   printf("\n The area = %f \n", area);

   printf("\n The area of circle C ");
   cir = 2 * 3.14 * c;
   printf("\n Area = %f \n", cir);

   printf("\n The area of circle B ");
   cirb = 2 * 3.14 * b;
   printf("\n Area = %f \n", cirb);

   printf("\n The area of circle A ");
   cira = 2 * 3.14 * a;
   printf("\n Area = %f \n", cira);

   printf( " \n The area of rectangle length A and Breadth C");
   rec = a * c;
   printf("\n  Area = %f \n ", rec);

   printf(" \n To find the HCF and LCM of X,Y and Z");


   for(i = 1; i <= x || i <= y || i< z ; i++)
   {

   if( x%i == 0 && y%i == 0 && z%i ==0 )
      HCF = i;
   }

   printf("\n HCF is = %d \n", HCF);

   
   LCM = 0;

   if(x > y && x >z)
      max = step = x;
   else if (y> x && y> z )
      max = step = y;
   else
      max = step = z;

   while(1)
   {
      if(max%x == 0 && max%y == 0 && max%z == 0)
      {
         LCM = max;
         break;
      }

      max += step;
   }

   printf(" LCM is=  %d \n", LCM);


}
