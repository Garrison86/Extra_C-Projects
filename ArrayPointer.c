#include <stdio.h>

int main () {

   /* an array with 5 elements */
   double balance[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
   double *pTr;
   int i;

   pTr = balance;
 
   /* output each array element's value */
   printf( "Array values using pointer\n");
	
   for ( i = 0; i < 5; i++ ) {
      printf("*(pTr + %d) : %.2f\n",  i, *(pTr + i) );
   }
printf("\n\n");
   printf( "Array values using balance as address\n");
	
   for ( i = 0; i < 5; i++ ) {
      printf("*(balance + %d) : %.2f\n",  i, *(balance + i) );
   }
printf("\n\n\n");

printf("pTr++ = %p\n", pTr++);
printf("++pTr = %p\n", ++pTr);
printf("++*pTr = %.1lf\n", ++*pTr);
printf("++(*pTr) = %.1lf\n", ++(*pTr));
printf("*pTr++ = %.1lf\n", *pTr++);
printf("(*pTr)++ = %.1lf\n", (*pTr)++);
printf("*(pTr)++ = %.1lf\n", *(pTr)++);
printf("*++pTr = %lf\n", *++pTr);
printf("*(++pTr) = %lf\n", *(++pTr));
printf("\n\n\n");
   return 0;
}
/*
=========Output===========
Array values using pointer
*(pTr + 0) : 1.00
*(pTr + 1) : 2.00
*(pTr + 2) : 3.00
*(pTr + 3) : 4.00
*(pTr + 4) : 5.00


Array values using balance as address
*(balance + 0) : 1.00
*(balance + 1) : 2.00
*(balance + 2) : 3.00
*(balance + 3) : 4.00
*(balance + 4) : 5.00



pTr++ = 0x7fffffffdcb0
++pTr = 0x7fffffffdcc0
++*pTr = 4.0
++(*pTr) = 5.0
*pTr++ = 5.0
(*pTr)++ = 4.0
*(pTr)++ = 5.0
*++pTr = 0x5555555592a0
*(++pTr) = 0x5555555592a0


pTr++ = 0x7fffffffdcc0 // Pointer moves to the next int position (as if it was an array)
++pTr = 0x7fffffffdcd0 // Pointer moves to the next int position (as if it was an array)
++*pTr = 4.4 // The value pointed at by ptr is incremented
++(*pTr) = 5.4 // The value pointed at by ptr is incremented
*pTr++ = 5.4 // The value pointed at by ptr is incremented
(*pTr)++ = 17.0 // Pointer moves to the next int position (as if it was an array). But returns the old content
*(pTr)++ = 18.0 // Pointer moves to the next int position (as if it was an array). But returns the old content
*++pTr = 0x5555555592a0 // Pointer moves to the next int position, and then get's accessed, with your code, segfault
*(++pTr) = 0x5555555592a0 // Pointer moves to the next int position, and then get's accessed, with your code, segfault
==========================
#define N 100
int A[N], I, *pAr, sum=0;

pAr = A      is equal to    pAr = &A[0]
*(pAr + 1)   is equal to    A[1]

         ----in a loop----
*pAr        points to      A[0]  @0x300
*pAr++      now points to  A[1]  @0x304
*pAr++      now points to  A[2]  @0x308
            ect...


*/