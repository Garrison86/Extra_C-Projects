   //=========================================================================
   // pointer = a "variable-like" reference that holds a memory address to 
   //           another variable, array, etc.
   //
   //           some tasks are performed more easily with pointers.
   //           * called the "indirection operator" or aka (value at address)
   //           to display the address use the %p format specifier.
   //           the & (ampersand) is the "address of operator".
   //=========================================================================

#include <stdio.h>

void printAge(int *pAge){
   printf("You are %d years old\n", *pAge);
}



int main()
{
   int age = 21; // "int = int"
   int *pAge = &age; //declaring a pointer "address = address"
   // int *pAge = NULL; // good practice to assign NULL if decalaring a pointer

   printAge(pAge);//dereference = "You are 21 years old"
   printf("\n");
   printf("value at age: %d\n", age);
   printf("value at *pAge: %d\n", *pAge);
   printf("address of &age: %p\n", &age); // address of &age: 0x7fffffffdce0
   printf("value of pAge: %p\n", pAge); // value of pAge: 0x7fffffffdce0
   printf("something of &pAge: %p\n" , &pAge); // something of &pAge: 0x7fffffffdce8
   printf("\n");
   printf("sizeOf(&pAge) = %p\n", sizeof(&pAge)); // = 0x8
   printf("sizeOf(pAge) = %p\n", sizeof(pAge)); // = 0x8
   printf("sizeOf(*pAge) = %p\n", sizeof(*pAge)); // = 0x4
   printf("\n");  
   printf("size of age: %d bytes\n", sizeof(age)); // = 4 bytes
   printf("size of pAge: %d bytes\n", sizeof(pAge)); // = 8 bytes
   printf("\n");
   printf("value of age: %d\n", age); // value at the address of the variable = 21
   printf("value at *pAge: %d\n", *pAge); //dereferencing using the * "value at address" = 21
   printf("\n\n\n");



int myAge = 43;     // An int variable
int* pTr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge

printf("%d\n", myAge);// the value of myAge = 43
printf("%p\n", &myAge);// memory address of myAge = 0x7fffffffdce4
printf("%p\n", pTr);// Reference = 0x7fffffffdce4
printf("%d\n", *pTr);// Dereference: value of myAge with the pointer = 43
  printf("\n");
printf("sizeop(myAge) = %d\n", sizeof(myAge));
printf("sizeop(&myAge) = %d\n", sizeof(&myAge));
printf("sizeop(pTr) = %d\n", sizeof(pTr));
printf("sizeop(*pTr) = %d\n", sizeof(*pTr));
//int myAge = 43;     // Variable declaration
//int* pTr = &myAge;  // Pointer declaration
//int* myNum; // Most used
//int *myNum;
//int * myNum;
 printf("\n\n\n");
   return 0;
}
/*
============Out=Put===============
You are 21 years old
address of &age: 0x7fffffffdce0
value of pAge: 0x7fffffffdce0
something of &pAge: 0x7fffffffdce8

sizeOf(&pAge) = 0x8
sizeOf(pAge) = 0x8
sizeOf(*pAge) = 0x4

size of age: 4 bytes
size of pAge: 8 bytes

value of age: 21
value at *pAge: 21



43
0x7fffffffdce4
0x7fffffffdce4
43

sizeop(myAge) = 4
sizeop(&myAge) = 8
sizeop(pTr) = 8
sizeop(*pTr) = 4
=================================
additional info
   ptr++;    // Pointer moves to the next int position (as if it was an array)
   ++ptr;    // Pointer moves to the next int position (as if it was an array)
   ++*ptr;   // The value pointed at by ptr is incremented
   ++(*ptr); // The value pointed at by ptr is incremented
   ++*(ptr); // The value pointed at by ptr is incremented
   *ptr++;   // Pointer moves to the next int position (as if it was an array). But returns the old content
   (*ptr)++; // The value pointed at by ptr is incremented
   *(ptr)++; // Pointer moves to the next int position (as if it was an array). But returns the old content
   *++ptr;   // Pointer moves to the next int position, and then get's accessed, with your code, segfault
   *(++ptr); // Pointer moves to the next int position, and then get's accessed, with your code, segfault


*/