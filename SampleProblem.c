#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int search, key, arrayItems;
int searchArray(int ar[], int k); // forward declaration
void addElements(int ar[], int inputValue); // forward declaration
//===================Main===================
int main(void)
{
    int found = -1;
    int array[MAX];
    addElements(array, arrayItems);
    printf("\n\n");
    while (1){
        found = searchArray(array, key);
        printf("\n");
    }
}
//==================End=main===============

int searchArray(int ar[], int k){
    int a = -1;
    int indexFound = 0;
    printf("Enter the value to search for: \n");
    scanf("%d", &k);
    for (int i = 0; i < MAX; i++){
        if (ar[i] == k){
            a = k;
            indexFound = i + 1;
        }
    }
    if (a != -1){
        printf("%d is found in position %d\n", a, indexFound);
    }else{
        printf("%d is not found in the array\n", k);
    }
    return a;
}

void addElements(int ar[], int inputValue){
    int count=0;
    while(count < MAX){
    printf("Enter array Element %d: \n", ++count);
    scanf("%d", &inputValue);
    ar[count-1] = inputValue;
    }
}
